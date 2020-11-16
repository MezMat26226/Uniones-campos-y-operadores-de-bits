#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "sim7SegWin.c"
#define puerto 0x378
int main()
{
	unsigned char numeros[]={63,6,91,79,102,109,125,7,127,103};
	unsigned char n[]={63,63,63,63,63};
	int num,i;
	ioperm(puerto,1,1);
	outb(0,puerto);
	for(i=9;i>=0;i--){
		outb(numeros[i],puerto);
		Sleep(1000);
	}
	for(i=0;i<5;i++){
		outb(n[i],puerto);
		Sleep(1000);
	}
	outb(0,puerto);
	ioperm(puerto,1,0);
	system("pause");
	return 0;
}
