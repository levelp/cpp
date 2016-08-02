system("chcp 65001");
setlocale(LC_ALL, "Russian.UTF-8");
SetConsoleCP(65001);
SetConsoleOutputCP(65001);
QTextCodec* tc = QTextCodec::codecForName("IBM 866");
cout << QString(tc->fromUnicode("Юникод СТрока :)")).data() << endl;
MySQL   number_of_lessons
MSSQL   NumberOfLessons
ORACLE  NUMBER_OF_LESSONS
[main.cpp](main.cpp)

