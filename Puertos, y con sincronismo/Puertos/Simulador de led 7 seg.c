#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "sim7SegWin.c"
#define puerto 0x378
int main()
{
	unsigned char numeros[] = {63,6,91,79,102,109,125,7,127,103}; //Estos numeros en decimales, corresponden a
	int num;                                                      // = 0,1,2,3,4,5,6,7,8,9 en binario
	ioperm(puerto,1,1);
	outb(0,puerto);  //Con esto, primero muestro "los leds apagados"
	printf("Ingrese el numero que desea mostrar (termina con un numero mayor a 9 o menor a 0): ");
	scanf("%d",&num);
	while(num>=0&&num<=9){
		outb(numeros[num],puerto);
		printf("Ingrese el numero que desea mostrar (termina con un numero mayor a 9 o menor a 0): ");
		scanf("%d",&num);
	}
	ioperm(puerto,1,0);
	printf("\n\tFin del programa.\n\n");
	system("pause");
	return 0;
}
