#include <stdio.h>

int main()
{
    //1
    int a[2] = {0, 1};
    int const *b = a;

    //2
    const int c = 99;
    int const *d = &c;
    
    c++;
    
    //3
    int const k = 100;
    //k = 200; const이므로 오류가 난다.

    //1
    *(int *)b = 200; //const 벗기기
    
    //2
    *(int *)d = 200;

    //1
    printf("%d %d\n", a[0], a[1]);
    
    //2
    printf("%d\n", c);

}