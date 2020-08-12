#include <stdio.h>

int main()
{
    int a[2]={0};
    int const *b = a;

    *(int *)b = 200;
    printf("%d %d\n", a[0], a[1]);
}