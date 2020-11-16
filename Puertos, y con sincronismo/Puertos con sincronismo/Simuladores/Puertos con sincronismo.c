#include<stdio.h>
#include<stdlib.h>
#include "sim10.c"
#define puerto 0x400
void listar(int []);
struct CB{
	int S:1;
	int M:3;
	int  :3;
	int F:3;
};
union UNI{
	struct CB DATO;
	unsigned char BYTE;
};
int main()
{
	union UNI U;
	int fin=0;
	int personas[8]={0};
	ioperm(puerto,1,1);
	while(!fin)
	{
		do
		{
			U.BYTE=inb(puerto); //Lee el puerto las veces que sean necesarias hasta leer un 1, que se considera
		}while(U.DATO.S==0);    //como información valída
		
		if(U.DATO.F==1)	 //Me pregunto si el bit más significativo no es 1, para seguir con la operación
		{
			fin=1;
		}
		else
		{
			personas[U.DATO.M]++; //Le doy valores al vector
			do
			{
				U.BYTE=inb(puerto);
				
			}while(U.DATO.S==1);/*Se espera a que el bit de sincronismo pase a cero (0) nuevamente. 
								Sino, se analiza el mismo dato más de una vez.
	                      	    Como si una persona pasara muchas veces , en vez de una vez:			    
							    S=0 No hay datos.
			          		    S=1 Nuevo dato.
			                    S=0 Cambio de bit de sincronismo.
			                    S=1 Nuevo dato.*/
		}
	}
	listar(personas);
	ioperm(puerto,1,0);
	printf("\n\n\tFin del programa.\n\n");
	system("pause");
	return 0;
}
void listar(int personas[8])
{
	int i;
	printf("Molinete\t Personas\n");
	for(i=0;i<8;i++)
	{
		printf("%d\t\t%d\n",i,personas[i]);
	}
}
