/*Los campos de bits son estructuas con campos enteros cuyas longitudes en bits pueden ser seleecionadas en forma
individual en un rango comprendido entre 1 y el máximo del tipo*/
#include<stdio.h>
struct BITS{
	int A:5; 
	int B:7;
	int C:4; 
};
union BYTES{
	struct BITS X;
	short int NUM;
};
int main()
{
	union BYTES Z;
	printf("Ingrese un numero: ");
	scanf("%d",&Z.NUM);
	printf("\nCAMPO A: %d",Z.X.A);
	printf("\nCAMPO B: %d",Z.X.B);
	printf("\nCAMPO C: %d",Z.X.C);
}
