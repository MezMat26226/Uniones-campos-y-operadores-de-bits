#include<stdio.h>
struct BITS{
	int A:4;
	int B:1;
	int C:3;
};
union UNI{
	char CAR;
	struct BITS BIT;
};
int main()
{
	union UNI X;
	X.CAR = 411;
	X.CAR <<= 3;
	X.BIT.A = 30;
	printf("\n CAR = %d  A = %d  B = %d  C = %d",X.CAR,X.BIT.A,X.BIT.C,X.BIT.C);
}
