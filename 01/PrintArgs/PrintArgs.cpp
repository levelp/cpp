#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

FILE* stream;

int main(int argc, char* argv[]) {
  freopen_s(&stream, "output.txt", "w", stdout);
  printf("Number of arguments (argc) = %d\n", argc);

  for (int i = 0; i < argc; ++i)
    printf("arg[%d] = \"%s\"\n", i, argv[i]);

  fflush(stdout);
  return 0;
}

