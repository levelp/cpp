int sum(int a, int b) {
  return a + b;
}

// Количество делителей
int divisors(int N) {
  int res = 0;

  for(int i = 1; i <= N; ++i)
    if(N % i == 0)
      res++;

  return res;
}

