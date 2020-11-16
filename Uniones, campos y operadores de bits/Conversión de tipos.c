/*Conversión de tipo con uniones*/
#include<stdio.h>
union UN{
	float A;
	char BYTES[4];  //Al sobreescribir mi vector arriba de un entero, lo "desmembre"
};
main()
{
	union UN X;
	int I;
	X.A = 572.345;
	for(I=0;I<4;I++)
		printf("\nX.BYTES[%d] = %X",I,X.BYTES[I]);
	
}
