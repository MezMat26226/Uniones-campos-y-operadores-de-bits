/*Operadores de bits, desplazamientos*/
#include<stdio.h>
main()
{
	unsigned char NUM;
	printf("\nIngrese un numero entre 0 y 255: ");
	scanf("%d",&NUM);
	printf("Numero ingresado: %X",NUM);
	NUM>>=2;
	printf("\nNumero modificado: %X",NUM);
}
