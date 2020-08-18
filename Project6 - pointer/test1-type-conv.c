#include <stdio.h>

int main()
{
    int a[10] = {0, 0, 0, 1, 4, 5, 6, 7, 8, 9};
    //void *b;
    long long *c;
    //b = &a[0];
    c = (long long *)a;
    printf("%d, %d\n", a, *a);
    printf("%p, %llx\n", c, *c);
    printf("%p, %llx\n", c+1, *(c+1));
    float kk = 0.75f;
    printf("%f : int로 - %d, int를 16진수로 - %x \n", kk, *(int *)&kk, *(int *)&kk);
}