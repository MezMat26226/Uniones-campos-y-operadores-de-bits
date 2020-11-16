#include<stdio.h>
struct BITS{
	int A:1;
	int B:3;
	int C:4;
};
union UNI{
	char CAR;
	struct BITS BIT;
};
int main()
{
	union UNI X;
	X.CAR = 921;
	X.BIT.B = 55;
	X.BIT.B >>=2;
	printf("\nCAR = %d\tA = %d\tB = %d\tC = %d",X.CAR,X.BIT.A,X.BIT.B,X.BIT.C);
}
