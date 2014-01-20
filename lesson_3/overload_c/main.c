#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main()
{
    printf("%d\n", MAX(1,2));
    printf("%c\n", MAX('a','b'));
    printf("%c\n", MAX('a',2));
    printf("%c\n", MAX('a',2));
    return 0;
}
