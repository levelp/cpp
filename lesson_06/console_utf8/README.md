<!-- doc.py -->
setlocale(LC_CTYPE,"rus");
setlocale(LC_CTYPE,"rus.1251");
setlocale(LC_CTYPE,NULL);
setlocale(LC_ALL, "ru_RU.UTF-8");
setlocale(LC_CTYPE, "UTF-8");
setlocale(LC_ALL, "UTF-8");
SetConsoleOutputCP(CP_UTF8);
SetConsoleOutputCP(CP_UTF8);
system("chcp 65001");
locale u("rus_RUS.utf8"); // или rus.utf8, или просто .utf8 ?
cout.imbue(u);
[main.cpp](main.cpp)

