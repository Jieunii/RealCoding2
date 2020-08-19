#include <stdio.h>

int main(void) {
	int n1=10, n2=20, n3=30;
	int * p1=&n1;
	const int * p2=&n1; //int를 상수화하겠다.
	int * const p3=&n1; //p3를 상수화하겠다. p3의 주소값을 못바꾸게 하겠다.
	const int * const p3=&n1;
	
	(*p1)++;
	(*p2)++; //p2의 내용물을 변경할 수 없다.
	(*p3)++;
	(*p4)++; //p4 변경 x

	p1 = &n2;
	p2 = &n2;
	p3 = &n2; //p3를 변경할 수 없다.
	p4 = &n2; //p4 변경 x
	
	return 0;
}
