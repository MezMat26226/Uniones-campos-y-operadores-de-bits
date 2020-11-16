#include<stdio.h>
#include<stdlib.h>
#include "simledsWin.c"
#define puerto 0x378
int main()
{
	int n;
	ioperm(puerto,1,1);
	printf("Ingrese un numero del 0 al 7 (otro para terminar): ");
	scanf("%d",&n);
	while(n>=0&&n<=7){
		outb(0x01<<n,puerto); //Desplazo los bits hacia la izquierda "n" veces
		printf("Ingrese un numero del 0 al 7 (otro para terminar): ");
		scanf("%d",&n);
	}
	ioperm(puerto,1,0);
	printf("\n\tFin del programa.\n\n");
	system("pause"); 
	return 0;
}
