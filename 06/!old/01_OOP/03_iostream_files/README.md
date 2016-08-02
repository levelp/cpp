Файловый ввод и вывод с помощью потоков
---------------------------------------
``` cpp
#include <fstream> // Файловый ввод и вывод с помощью потоков
```

``` cpp
  ifstream in("in.txt");
  ofstream out("out.txt");

  int a, b;
  in >> a >> b;
  out << "a + b = " << (a + b) << endl;

  in.close();
  out.close();
```

[a_sum.cpp](a_sum.cpp)

cin - istream;
cout - ostream;
ifstream - input file stream

Открываем текстовый файл для ввода
``` cpp
  ifstream in("data.txt");
  string s;
  double x, y;
  in >> s >> x >> y;
  cout << s << " " << x << " " << y <<
       "   x + y = " << (x + y) << endl;
  in.close();
```

Перенаправляем вывод в файл **log.txt**:
``` cpp
  freopen("log.txt", "a", stdout);

  cout << "Квадраты чисел:" << endl;

  for(int i = 0; i < 10; ++i)
    cout << i << "^2 = " << i* i << endl;

```

Выходной файл автоматически
закрывается при закрытии программы
[main.cpp](main.cpp)

Перенаправление консольного ввода/вывода
----------------------------------------
Подключаем cstdio для **freopen**
``` cpp
#include <cstdio>
```

Ввод из файла вместо консоли:
``` cpp
  freopen("sum.in", "r", stdin); // stdin - поток ввода с консоли
```

Вывод в файл вместо консоли:
``` cpp
  freopen("sum.out", "w", stdout);
```

Дальше работаем с файлами как с консолью
``` cpp
  long long a, b;
  cin >> a >> b;
  cout << a << " + " << b << " = " << (a + b) << endl;
```

[redirect_output.cpp](redirect_output.cpp)

