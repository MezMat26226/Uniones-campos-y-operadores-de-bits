#include<stdio.h>
#include<stdlib.h>
#include "simledsWin.c"
#define puerto 0x378
int main()
{
	unsigned char num, led;
	ioperm(puerto,1,1);
	//Ingreso el numero
	printf("\n\tIngrese un numero de 0 a 7, otro para terminar: ");
	scanf("%d",&num);
	//Algoritmo
	while(num>=0&&num<=7){
		switch(num){
			case 0: led=0x01;
						break;
			case 1: led=0x02;
						break;
			case 2: led=0x04;
						break;
			case 3: led=0x08;
						break;
			case 4: led=0x10;
						break;
			case 5: led=0x20;
						break;
			case 6: led=0x40;
						break;
			case 7: led=0x80;
						break;																								
		}
		//Se prende el led
		outb(led,puerto);
		//Ingreso de otro numero
		printf("\n\tIngrese un numero de 0 a 7, otro para terminar: ");
		scanf("%d",&num);
	}
	ioperm(puerto,1,0);
	printf("\n\t\tFin del programa.\n\n");
	system("pause");
	return 0;
}
