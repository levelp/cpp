<!-- doc.py -->
Перевод
Как ввести строку целиком?
Как читать
system("chcp 65001");
SetConsoleCP(65001);
SetConsoleOutputCP(65001);
freopen("out.txt","w",stdout);
Ключ - слово по-английски,
значение - слово по-русски
Словарь = Ассоциативный массив
int p = 1;
fclose(stdin); // !!!
cin >> p;
Считываем
Смотрим в словаре
const int strLen = 1024;
char phrase[strLen];
cin.getline(phrase, strLen);
cout << phrase << endl;
Ищем слово из словаря в строке
cout << inEnglish << " pos " << pos << endl;
[main.cpp](main.cpp)

