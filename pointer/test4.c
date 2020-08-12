#include <stdio.h>

int main()
{
    int a[10], b[10], c[10];
    int * t[3];
    t[0] = a;
    t[1] = b;
    t[2] = c;
    t[1][35] = 200;
    printf("%d\n", b[35]);
}