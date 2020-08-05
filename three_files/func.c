//func.c file

#include <math.h>
#include <stdio.h>
#include "func.h"

int func_name_or_id()
{
#ifdef PRINT_ID
	printf("ID : 201723273\n");
	return 0;
#else
	printf("Name : JieunYoon\n");
	return 1;
#endif
}