C++
Вывод в консоль по-русски:
``` cpp
  //system("chcp 65001");
  SetConsoleOutputCP(CP_UTF8);
  //std::locale::global(std::locale ("en_US.UTF-8"));
  printf("Это моя первая программа!\n");
  //cout << "Текст в UTF-8" << endl;
  //cout << "И он нормально читается в Windows-консоли!" << endl;
```

[hw_utf8.cpp](hw_utf8.cpp)

C++
Вывод в консоль по-русски:
``` cpp
  //setlocale(LC_ALL, "Russian_Russia.UTF-8");
  //setlocale(LC_ALL, "Russian.UTF-8");
  //SetConsoleCP(CP_UTF8);
  //SetConsoleOutputCP(CP_UTF8);
```

[hw_utf8_2.cpp](hw_utf8_2.cpp)

Получаем параметры текущей локали
``` cpp
#include <windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  char language[256] = {0}, country[256] = {0};
  GetLocaleInfo(
    GetUserDefaultLCID(),
    LOCALE_SENGLANGUAGE,
    language, sizeof(language));
  GetLocaleInfo(
    GetUserDefaultLCID(),
    LOCALE_SENGCOUNTRY,
    country, sizeof(country));

  UINT OEM_CP = GetOEMCP(); // Возвращает системную OEM кодовую страницу как число
  // UINT ANSI_CP = GetANSICP();

  printf("%s_%s %d\n", language, country, OEM_CP);

  cout << language << "_" << country << "." << OEM_CP << endl;
}
```

[show_cur_locale.cpp](show_cur_locale.cpp)

