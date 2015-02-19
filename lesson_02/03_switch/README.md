Множественный выбор switch
==========================
Вводим количество углов
``` cpp
  int N;
  cout << "Enter number of edges: ";
  cin >> N;
```

``` cpp
  switch(N) {
    case 1: // 1 угол => точка
      int i = 1, j = 10;

      for(int k = 0; k < 10; ++k) {

      }

      cout << "point" << endl; // Точка
      break;

    case 0: // 0 углов => пустота или круг
      cout << "emptiness / circle" << endl;
      break;

    case 2: // 2 угла => отрезок
      cout << "segment" << endl;
      break;

    case 3: // 3 угла => треугольник
      cout << "triangle" << endl;
      break;

    case 4: // 4 угла => четырёхугольник
    case 5:
      // Общая обработка для случаев N = 4,5
      cout << N << "th polygon" << endl;
      break;

    case -1:
      cout << "-1" << endl;

    case -2:
      cout << "-2" << endl;

    default:  // N < 0 => ошибка, N >= 5 углов => N-угольник
      cout << ((N < 0) ? "error" : "N-edged polygon") << endl;
      break;

    case -3:
      cout << "-3" << endl;
  }

```

[main.cpp](main.cpp)

