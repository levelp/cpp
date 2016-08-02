Перенаправляем все сообщения
которые программа выводит в текстовую
консоль в файл
freopen("stdout.txt", "w", stdout);
freopen("stderr.txt", "w", stderr);
system("pause");
[main.cpp](main.cpp)

