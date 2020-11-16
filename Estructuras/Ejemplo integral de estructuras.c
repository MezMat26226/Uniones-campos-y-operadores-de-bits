#include<stdio.h>
#include<string.h>
#define MAX 200
#define MAX_MAT 12
struct SOLDADO{
	int LEGAJO;
	char NOM[20];
	int NOTA[MAX_MAT];
	char DISPONIBLE;
};
void ingreso(struct SOLDADO [], int );
void ordena(struct SOLDADO [], int , int );
int main()
{
	struct SOLDADO DATO[MAX];
	int I,CODIGO,CANTIDAD,VACANTES = MAX;
	/*INGRESO*/
	ingreso(DATO,MAX);
	while(VACANTES){
		/*PEDIDOS*/
		printf("\n\nIngrese codigo de asignatura preferencial: ");
		scanf("%d",&CODIGO);
		CODIGO --; /*Ajuste a la posicion del vector*/
		printf("\n\nIngrese la cantidad de comandos solicitada: ");
		scanf("%d",&CANTIDAD);
		/*ORDENAMIENTO*/
		ordena(DATO,MAX,CODIGO);
		/*ASIGNACIÓN*/
		if(VACANTES<CANTIDAD){
			printf("NO ALCANZAN");
			VACANTES = 0;
		}
		else{
			VACANTES -= CANTIDAD;
		}
		for(I=0;(I<MAX)&&CANTIDAD;I++){
			if(DATO[I].DISPONIBLE){
				DATO[I].DISPONIBLE = 0;
				CANTIDAD --;
				printf("\n\t%d\t%20s\t%d",DATO[I].LEGAJO,DATO[I].NOM,DATO[I].NOTA[CODIGO]);
			}
		}
	}
}
void ingreso(struct SOLDADO FICHA[], int N)
{
	int I,J;
	for(I=0;I<N;I++){
		printf("\nLegajo: ");
		scanf("%d",&FICHA[I].LEGAJO);
		fflush(stdin);
		printf("\nNombre: ");
		gets(FICHA[I].NOM);
		printf("\nNotas: ");
		for(J=0;J<MAX_MAT;J++){
			scanf("%d",&FICHA[I].NOTA[J]);
			FICHA[I].DISPONIBLE = 1;
		}
	}
}
void ordena(struct SOLDADO FICHA[], int N, int CODIGO)
{
	int I,J;
	struct SOLDADO AUX;
	for(I=0;I<N-1;I++){
		for(J=0;J<N-1;J++){
			if(FICHA[J].NOTA[CODIGO]<FICHA[J+1].NOTA[CODIGO]){
				AUX = FICHA[J];
				FICHA[J] = FICHA[J+1];
				FICHA[J+1] = AUX;
			}
		}
	}
}
