#include <stdio.h>

void printData_1(const short *data)//값 변경을 못하게 할 때
{
	int i;

	for(i=0; i<5; i++) {
		printf("%d,%d\n", data[i], *(data+i));
		//data[i] = 9999; //short * data일때
	}
}

void printData_2(short data[5])
{
	int i;

	for(i=0; i<5; i++) {
		printf("%d,%d\n", data[i], *(data+i));
	}
}

void updateData(short *data)
{
	int i;
	for(i=0; i<5; i++) data[i] += 10;
}

int main(void)
{
	short arr[5] = {1, 2, 3, 4, 5};

	printf("-------------------------\n");
	printData_1(arr);
	printf("-------------------------\n");
	printData_2(arr);
	printf("-------------------------\n");
	updateData(arr);
	printData_2(arr);

	return 0;
}
