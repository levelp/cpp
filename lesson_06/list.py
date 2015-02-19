# -*- coding: utf-8 -*-
import os
from random import randrange
from string import Template
import re


def subdirs():  # Подкаталоги каталога problems
    return [name for name in os.listdir('.') if os.path.isdir(name)]

# Берём список каталогов по алфавиту



def ReadTemplate(template_fn):
    return open("../templates/" + template_fn, 'r').read()


# Запись файла: t - шаблон, d - словарь значений, fn - имя файла
def GenFile(t, d, fn, overwrite=False):
    if not overwrite and os.path.isfile(fn):
        return
    print 'Gen "%s"' % fn
    f = open(fn, 'w')
    f.write(Template(t).safe_substitute(d))
    f.close()

# Порядок уроков
orderFile = "order.txt"
tasks = []
if os.path.isfile(orderFile):
    tasks = [x.lstrip().rstrip() for x in open(orderFile).readlines()]

if len(tasks) == 0:
    print("Create \"" + orderFile + "\"")
    tasks = subdirs()
    orderF = open(orderFile, 'w')
    for task in tasks:
        orderF.write("%s\r\n" % task)
    orderF.close()

macros = 'problAIOI'

# Пробегаем все задачи
l = []
test_dir = 'tests'
for TaskID in tasks:
    if TaskID == '.idea': continue
    # Генерация task.cfg
    d = {'TaskID': TaskID}
    GenFile(task_cfg, d, "%s/task.cfg" % TaskID, True)
    GenFile(task_cfg, d, "%s/tests/task.cfg" % TaskID, True)

    # Вычисляем количество тестов
    test_count = 0
    while True:
        test_count += 1
        testName2 = TaskID + '/' + test_dir + "/%02d" % test_count
        testName3 = TaskID + '/' + test_dir + "/%03d" % test_count
        if not os.path.isfile(testName2) and not os.path.isfile(testName3):
            test_count -= 1
            break
    print("%s - %d" % (TaskID, test_count))

    # Java checker
    javaCheckerFile = "%s/Check.java" % (TaskID)
    if os.path.isfile(javaCheckerFile):
        macros = 'problJIOI'

    # GenFile(solution,d,"%s/solution.dpr" % TaskID)
    # Если нет заготовки .tex файла, создаём её
    tex_file = "%s/%s.tex" % (TaskID, TaskID)
    if not os.path.isfile(tex_file):
        tex_file = "%s/statement/%s.tex" % (TaskID, TaskID)
    if not os.path.isfile(tex_file):
        tex_file = "%s/statement/%s.ru.tex" % (TaskID, TaskID)
    # GenFile(problem,d,tex_file)
    # Читаем заголовок tex файла
    tex_cont = open(tex_file, 'r').read()
    # x = re.findall(r'\\(?P<command>\w+)\{(?P<argA>.*?)\}\{(?P<argB>.*?)\}?\r?\n\{(?P<argC>.*?)\}.*' , tex_cont, re.U)
    x = re.findall(r'\\begin\{problem\}\s*\{([^\}]*)\}\s*\{([^\}]*)\}\s*\{([^\}]*)\}', tex_cont, re.U)
    if x:
        first = x[0]
        prob_name = first[0].decode('utf-8')
    else:
        prob_name = 'parse'

    if test_count == 0:
        print('NO TESTS!!! ' + TaskID)

    preliminary = 1
    preliminaryFile = "%s/preliminary.txt" % TaskID
    try:
        preliminaryF = open(preliminaryFile, 'r')
        preliminary = int(preliminaryF.readline().rstrip().lstrip())
        preliminaryF.close()
    except:
        preliminaryF = open(preliminaryFile, 'w')
        preliminaryF.write("%s" % preliminary)
        preliminaryF.close()

    balls = [0]
    ballsFile = "%s/balls.txt" % TaskID
    try:
        ballsF = open(ballsFile, 'r')
        balls = map(int, ballsF.readline().split())
        ballsF.close()
    except:
        print("ERROR")

    if sum(balls) != 100:
        print('GENERATE BALLS')
        realTests = (test_count - preliminary)
        balls = [1] * realTests
        while sum(balls) < 100:
            balls[randrange(0, realTests, 1)] += 1
        balls = sorted(balls)
        assert sum(balls) == 100

        # Добавляем тесты из условия
        balls = [0] * preliminary + balls

        # Баллы в строку
        ballsStr = " ".join(str(x) for x in balls)

        print('write: ' + ballsStr)
        ballsF = open(ballsFile, 'w')
        ballsF.write(ballsStr)
        ballsF.close()

    # Баллы в строку
    ballsStr = " ".join(str(x) for x in balls)

    d = {'id': TaskID, 'name': prob_name, 'balls': ballsStr, 'preliminary': preliminary}
    l.append(d)


# Генерируем включение условий задач в .tex файл условия
str = ""
problems = "problems = [\n"
Letter = ord('A')
for task in l:
    str += '\prob{%s}\n' % (task['id'])
    # ACM
    # problems += '\tproblAD (%s, "%s", %s)\n' % (chr(Letter), task['name'],task['id'])
    problems += '\t' + macros + ' (%s, "%s", "%s", "%s", %s)\n' % \
                                (chr(Letter), task['name'], task['id'], task['balls'], task['preliminary'])
    Letter += 1
problems += "];"
print problems
f = open('problems.cfg', 'w')
f.write(problems.encode('cp866'))
f.close()

# Генерируем tex файл условий задач
# st = ReadTemplate("statements.tex")
# st = st.replace('%problem_list%',str)
# st = st.replace('%contest_name%',unicode('').encode("utf-8"))
# f = open('140322_ln'+'.tex', 'w')
# f.write(st)
# f.close()

# Генерируем конфигурационный файл
# st = ReadTemplate("contest.cfg")
# st = st.replace('%problem_list%',unicode(problems).encode('cp866'))
# st = st.replace('%contest_name%',unicode(contest_name).encode('cp866'))
# f = open('..\\'+contest_id+'.cfg', 'w')
# f.write(st)
# f.close()