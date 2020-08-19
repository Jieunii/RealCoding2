#include <stdio.h>

int add(int d1, int d2) {
	return d1+d2;
}
int sub(int d1, int d2) {
	return d1-d2;
}
int mul(int d1, int d2) {
	return d1*d2;
}
int div(int d1, int d2) {
	if(d2) return d1/d2;
	else { printf("Zero Dived Error!!\n"); return 0; }
}

int main(void)
{
	int no, rst;
	//함수 포인터
	int (*fp) (int, int); //add의 타입을 적어야 한다. //int(int, int) *fp;
	//(*fp) : 포인터 변수이고 포인터 변수의 타입은 int(int,int)
	
	while(1) {
		do {
			printf("\nSelect(1.add, 2.sub, 3.mul, 4.div, 0.quit) => ");
			scanf("%d", &no);
		} while(no<0 || no>4);
		if(no == 0) break;

		switch(no){
			case 1: fp = &add; break;
			case 2: fp = sub; break;
			case 3: fp = mul; break;
			case 4: fp = &div; break;
		}
		
		rst = fp(10, 20);
		printf("rst => %d\n", rst);
	}

	return 0;
}
