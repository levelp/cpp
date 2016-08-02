Макросы для отладки
-------------------
``` cpp
#define MY_DEBUG
#ifdef MY_DEBUG
#define SHOW(x) cout << __FILE__ << ":" << __LINE__ << " " << #x << " = " << x << endl;
#else
#define SHOW(x) ;
#endif

#define ASSERT_EQ(a,b) ((a == b) ? (void)0 : _assert(#a" != "#b, __FILE__, __LINE__))
```

[main.cpp](main.cpp)

