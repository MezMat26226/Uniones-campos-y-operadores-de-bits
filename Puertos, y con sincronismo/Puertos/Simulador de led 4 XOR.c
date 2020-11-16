#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "simledsWin.c"
#define puerto 0x378
int main()
{
	unsigned char led = 0xAA, OFF = 0xFF;
	int i;
	outb(led,puerto);
	ioperm(puerto,1,1);
	for(i=0;i<50;i++){
		led = led^OFF; //Hago el primer XOR;
		outb(led,puerto);
		Sleep(400);
	}
	ioperm(puerto,1,0);
	system("pause");
	return 0;
}
