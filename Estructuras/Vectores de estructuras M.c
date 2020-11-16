#include<stdio.h>
#include<string.h>
#define N 3
/*Declaración del tipo*/
struct ALUMNO{
	char NOMBRE[20];
	char SEXO;
	float PROMEDIO;
};
/*Prototipos de funciones*/
void ingresar(struct ALUMNO V[], int NUM);
void ordenar(struct ALUMNO V[], int NUM);
void imprimir(struct ALUMNO V[], int NUM);
int main(void){
	struct ALUMNO DATO[N];
	ingresar(DATO,N);
	ordenar(DATO,N);
	imprimir(DATO,N);
}
void ingresar(struct ALUMNO V[], int NUM){
	int I;
	float F;
	for(I=0;I<NUM;I++){
		printf("\nIngrese el nombre del alumno: ");
		fflush(stdin);
		gets(V[I].NOMBRE);
		printf("\nIngrese el sexo M/F: ");
		V[I].SEXO = getchar();
		printf("\nIngrese el promedio del alumno: ");
		scanf("%f",&F);
		V[I].PROMEDIO = F;
	}
}
void ordenar(struct ALUMNO V[], int NUM){
	struct ALUMNO AUX;
	int I,J;
	for(I=0;I<NUM-1;I++){
		for(J=0;J<NUM-I-1;J++){
			if(strcmp(V[J].NOMBRE,V[J+1].NOMBRE)>0){
				AUX = V[J];
				V[J] = V[J+1];
				V[J+1] = AUX;
			}
		}
	}
}
void imprimir(struct ALUMNO V[], int NUM){
	int I;
	for(I=0;I<NUM;I++){
		printf("\n%20s%10c%12.2f",V[I].NOMBRE,V[I].SEXO,V[I].PROMEDIO);
	}
}
