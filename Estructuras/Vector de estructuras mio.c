#include<stdio.h>
#include<string.h>
#define N 5
struct ALUMNO{
	char NOMBRE[20];
	char SEXO;
	float PROM;
};
void ingresar(struct ALUMNO [], int );
void ordenar(struct ALUMNO [], int );
void imprimir(struct ALUMNO [], int );
int main(void){
	struct ALUMNO DATO[N];
	ingresar(DATO,N);
	ordenar(DATO,N);
	imprimir(DATO,N);
}
void ingresar(struct ALUMNO D[], int TAM){
	int I;
	float F;
	for(I=0;I<TAM;I++){
		printf("Ingrese el nombre del alumno nro %d: ",I+1);
		fflush(stdin);
		gets(D[I].NOMBRE);
		printf("Ingrese el sexo del alumno (F/M): ");
		fflush(stdin);
		scanf("%c",&D[I].SEXO);
		printf("Ingrese el promedio del alumno: ");
		scanf("%f",&F);
		D[I].PROM = F;
	}
}
void ordenar(struct ALUMNO D[], int TAM){
	struct ALUMNO AUX;
	int I,J;
	for(I=0;I<TAM-1;I++){
		for(J=0;J<TAM-I;J++){
			if(strcmp(D[J].NOMBRE,D[J+1].NOMBRE)>0){
				AUX = D[J];
				D[J] = D[J+1];
				D[J+1] = AUX;
			}
		}
	}
}
void imprimir(struct ALUMNO D[], int TAM){
	int I;
	for(I=0;I<TAM;I++){
		printf("\n%20s%10c%12.2f",D[I].NOMBRE,D[I].SEXO,D[I].PROM);
	}
}
