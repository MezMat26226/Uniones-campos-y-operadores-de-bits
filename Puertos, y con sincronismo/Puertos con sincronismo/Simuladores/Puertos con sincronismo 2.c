#include<stdio.h>
#include<stdlib.h>
#include "sim11.c"
#define puerto1 0x300
#define puerto2 0x301
#define N 16
struct CB{
	int S:1;
	int F:1;
	int Rad:10;
	int Cod:4;
};
union UNI{
	struct CB DATO;
	unsigned char BYTE[2];
};
struct INFO{
	int Acum_Rad;
	int Cont_Rad;
	float Prom_Rad;
};
void iniciar(struct INFO [], int );
void promedio(struct INFO [], int );
void imprimir(struct INFO [], int );
int main()
{
	union UNI U;
	struct INFO V[16];
	int fin=0;
	iniciar(V,N);
	ioperm(puerto1,2,1);
	while(!fin)
	{
		do
		{
			U.BYTE[0]=inb(puerto1); //Realizo la lectura del primer byte, para despues leer el segundo byte
		}while(U.DATO.S==0); //Condición de sincronismo
		
		if(U.DATO.F==1) //Verifico si no finalizo
		{
			fin=1;
		}
		else
		{
			U.BYTE[1]=inb(puerto2); //Aca realizo la lectura del segundo byte
			V[U.DATO.Cod].Acum_Rad+=U.DATO.Rad;
			V[U.DATO.Cod].Cont_Rad++;
			do
			{
				U.BYTE[0]=inb(puerto1);
				
			}while(U.DATO.S==1);
		}
	}
	ioperm(puerto1,2,0);
	promedio(V,N);
	imprimir(V,N);
	printf("\n\n\tFin del programa.\n\n");
	system("pause");
	return 0;
}
void iniciar(struct INFO V[], int TAM)
{
	int i;
	for(i=0;i<TAM;i++)
	{
		V[i].Acum_Rad=0;
		V[i].Cont_Rad=0;
		V[i].Prom_Rad=0;
	}
}
void promedio(struct INFO V[], int TAM)
{
	int i;
	for(i=0;i<TAM;i++)
	{
		if(V[i].Cont_Rad)
		{
			V[i].Prom_Rad=(float)V[i].Acum_Rad/V[i].Cont_Rad;
		}
	}
}
void imprimir(struct INFO V[], int TAM)
{
	int i;
	printf("Particula \t Promedio");
	for(i=0;i<TAM;i++)
	{
		printf("%9d \t",i);
		if(V[i].Prom_Rad){
			printf("%8.2f\n",V[i].Prom_Rad);
		}
		else{
			printf("%8s\n","**SIN DATOS**");
		}
	}	
}
