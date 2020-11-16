#include<stdio.h>
#include<windows.h>
#include "sim7SegWin.c"
#define puerto 0x378
int main()
{
	unsigned char numeros[]={118,63,56,119};
	int i;
	ioperm(puerto,1,1);
	outb(0,puerto);
	for(i=0;i<4;i++){
		outb(numeros[i],puerto);
		Sleep(500);
	}
	outb(0,puerto);
	printf("\t\nFin del programa.\n\n");
	system("pause");
	return 0;
}
