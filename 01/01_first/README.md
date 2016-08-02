Windows
-------

Visual Studio... Кодировка текста Windows-1251
Консоль в Windows: cp866 - для совместимости с MS-DOS

``` cpp
  setlocale(LC_ALL, "Russian");
```

Первая программа на чистом C
----------------------------
Подключаем библиотеку: **stdio.h**
``` cpp
/* Hello World на C
   Многострочный комментарий...
*/
#include <stdio.h> /* Подключаем библиотеку */
// Директива препроцессора, вставляющая содержимое файла stdio.h
// #include <stdlib.h> /* ..ещё одну библиотеку */
//#include <iostream> // Для C++

int main() {
  printf("C: Hello world!\n");
  //std::cout << "Test" << std::endl;  // Для C++
  return 0;
}
```

Кодировка файла: cp866 win1251
[helloworld.c](helloworld.c)

Первая программа на C++
-----------------------
В C++ используем библиотеку STL **iostream**
В С - библиотеки с расширением *.h*
В С++ - библиотеки без расширения
``` cpp
// Hello World на C++
#include <iostream>
#include <stdio.h> // для совместимости
#include <cstdio> // в программе на C++ подключаем C
#include <vector>
// STL - Standart Template Library

using namespace std;

int main() {
  //cout << "C++: Hello world!" << endl;
  std::cout << "C++: Hello world!" << std::endl;
  return 0;
}
```

[helloworld.cpp](helloworld.cpp)

Общая структура программы. Использование комментариев (практика: комментарии до кода)
-------------------------------------------------------------------------------------
Подключение библиотек:
Заголовочные файлы в C++ без расширения
``` cpp
#include <iostream>
#include <cstdlib>
```

Глобальные переменные:
``` cpp
int x = 1, y = 10;
```

Функции:
``` cpp
int f() {
  return 1;
}
```

Основная программа - функция *main*
``` cpp
using namespace std; // Пространство имён, чтобы не писать везде std::cin

int main() { // Основная функция
  cout << "Enter two numbers: "; // Выводим на экран
  int a, b; // Объявляем 2 переменные целого типа
  std::cin >> a >> b; // Вводим их с клавиатуры
  std::cout << a << " + " << b << " = " << a + b << std::endl; // Вывод суммы
  system("pause"); // Нажмите любую клавишу...
  return 0; // Программа завершилась удачно, 0 - код возврата
}
```

[main.cpp](main.cpp)

Чистый C
#include <stdlib.h>
[main2.c](main2.c)

C++
Вывод в консоль по-русски:
``` cpp
  setlocale(LC_ALL, "Russian");
```

[main_rus.cpp](main_rus.cpp)

