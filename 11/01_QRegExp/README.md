Регулярные выражения
====================

Поиск e-mail
------------

(\w+@(?:\w+\.)+\w+) \-? (\w+)

mail1@mail.ru - Petrov  mail2@mail.ru.com  Ivanov
mail2@mail.ru.ww.com - Sidorov

>> mail1@mail.ru  Petrov
>> mail2@mail.ru.com  Ivanov
>> mail2@mail.ru.ww.com  Sidorov

PCRE - Perl Comp Reg Exp

Работа с регулярными выражениями
Запуск модульных тестов
[main.cpp](main.cpp)

Сразу при старте приложения применяется регулярное выражение
Каталог "Мои документы"
Когда текст выражения меняется, его надо заново применить
Когда текст меняется, заново применяем регулярное выражение
Очищаем окно результатов
Создаём новое регулярное выражение на основе строки
Создаём экземпляр регулярного выражения
Задаём "жадность регулярного выражения"
Если регулярное выражение некорректно,
то сразу выходим и выводим сообщение об ошибке в консоль
Текст для применения регулярного выражения
http://qt-project.org/doc/qt-5/qregexp.html#indexIn
Длина найденного куска
Собираем группы в скобках в одну строку
rx.captureCount() - количество найденных групп символов
rx.cap(i) - i-ая группа
rx.cap(1) + " - " + rx.cap(2));
QString("  len = %1").arg(len));
Защита от зацикливания программы
Сохраняем текст в текстовый файл
QFileDialog содержит статические методы для вызова различных стандартных диалогов
Мои документы
C:\\Users\\Денис\\Desktop
Загрузка текстового файла
Мои документы
Рабочий стол текущего пользователя
QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)
QDir::homePath() + "\\Desktop",
Второй вариант: QString data = QString::fromUtf8(array);
Выбор шрифта пользователем
Пользователем выбран новый шрифт
Диалог отменён
[mainwindow.cpp](mainwindow.cpp)

Применение регулярного выражения к тексту
с выводом результата обратно на форму
Сохранение текста в файл
Загрузка текста из файла
При обновлении текста
[mainwindow.h](mainwindow.h)

Символы
Поиск подстроки
Выделяем цифры из строки
c  - с помощью регулярных выражений можно искать обычные подстроки
\c A character that follows a backslash matches the character itself, except as specified below. e.g., To match a literal caret at the beginning of a string, write \^.
\a Matches the ASCII bell (BEL, 0x07).
\f Matches the ASCII form feed (FF, 0x0C).
\n Matches the ASCII line feed (LF, 0x0A, Unix newline).
ASCII 10 - Начало строки
\r Matches the ASCII carriage return (CR, 0x0D).
\t Matches the ASCII horizontal tab (HT, 0x09).
\v Matches the ASCII vertical tab (VT, 0x0B).
\xhhhh Matches the Unicode character corresponding to the hexadecimal number hhhh (between 0x0000 and 0xFFFF).
QCOMPARE(QRegExp("\\xD0BF").exactMatch("П"), true);
\0ooo (i.e., \zero ooo)    matches the ASCII/Latin1 character for the octal number ooo (between 0 and 0377).
. (dot)    Matches any character (including newline).
Группы символов
Кванторы
+ - один и больше
* - ноль и больше
[qregexptest.cpp](qregexptest.cpp)

Тестирование стандартных выражений QRegExp (PCRE - Perl Comp Reg Exp)
Символы
Группы символов
Кванторы
[qregexptest.h](qregexptest.h)


