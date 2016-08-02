Константы в if ставятся на первое место (до =)
``` cpp
const int a = 0;

int main() {
  int b = 0;

  if(a == b)
    cout << "a = b" << endl;
  else
    cout << "a != b" << endl;

  return 0;
}
```

[main.cpp](main.cpp)

