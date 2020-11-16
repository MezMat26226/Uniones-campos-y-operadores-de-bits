#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "simledsWin.c"
#define puerto 0x378
#define tiempo 200
int main()
{
	unsigned int i,j,k;
	ioperm(puerto,1,1);
	for(i=0;i<10;i++){
		for(j=0;j<7;j++){
			outb(0x01<<j,puerto);
			Sleep(tiempo);
		}
		for(k=0;k<7;k++){
			outb(0x80>>k,puerto);
			Sleep(tiempo);
		}
	}
	ioperm(puerto,1,0);
	printf("\t\nFin del programa.\n\n");
	system("pause");
	return 0;
}
