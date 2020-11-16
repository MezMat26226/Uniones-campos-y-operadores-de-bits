#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "sim7SegWin.c"
#define puerto 0x378
int main()
{
	unsigned char numero[]={63,6,91,79,102,109,125,7,127,103};
	int t,i,num;
	ioperm(puerto,1,1);
	outb(0,puerto);
	printf("Digite una tecla pra comenzar: "); scanf("%d",&t);
	for(i=0;i<10;i++){
		outb(numero[i],puerto);
		Sleep(500);
	}
	for(i=8;i>=0;i--){
		outb(numero[i],puerto);
		Sleep(500);
	}
	ioperm(puerto,1,0);
	printf("\t\nFin del programa.\n\n");
	system("pause");
	return 0;
}
