/*Operadores de bit*/
#include<stdio.h>
#define MASK 0x04
/*
int main()        
{
	unsigned char NUM;
	printf("\nIngrese un numero entre 0 y 255: ");
	scanf("%d",&NUM);
	if(NUM&MASK)  OPERADOR AND "&" 
		printf("El bit 2 es un 1");
	else
		printf("El bit 2 es un 0");	
} */
int main()
{
	unsigned char NUM;
	unsigned char RES;
	printf("\nIngrese un numero entre 0 y 255: ");
	scanf("%d",&NUM);
	RES = NUM|MASK; //Operador OR "|"
	printf("\nNUMERO MODIFICADO: %u",RES);	
}
