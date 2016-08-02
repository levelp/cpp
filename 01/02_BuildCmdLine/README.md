Скрипт для сборки из командной строки Windows
---------------------------------------------
``` bat
@echo Build exe-file:
g++ a.cpp -Wall -O3 -o MyFile.exe
@echo Run file:
MyFile.exe
```

Сборка из командной строки
--------------------------
``` cpp
#include <iostream>

int main() {
  int i = 2 * 3;
  std::cout << "Hello world! " << i << std::endl;
  return 0;
}
```

[a.cpp](a.cpp)

