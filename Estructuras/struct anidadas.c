#include<stdio.h>
#include<string.h>
#define N 5
struct FECHA{
	int DIA;
	int MES;
	int ANIO;
};
struct ALUMNO{
	char NOMBRE[20];
	struct FECHA NACIM; // Campo de estructura ALUMNO, es una variable de tipo "struct FECHA"
	float PROM;
};
void ingresar(struct ALUMNO [], int );
void ordenar(struct ALUMNO [], int );
void imprimir(struct ALUMNO [], int );
unsigned int dias(struct FECHA );
int main(void){
	struct ALUMNO DATO[N];
	ingresar(DATO,N);
	ordenar(DATO,N);
	imprimir(DATO,N);
}
void ingresar(struct ALUMNO V[], int TAM){
	int I;
	float F;
	for(I=0;I<TAM;I++){
		printf("Ingrese el nombre del alumno %d: ",I+1);
		fflush(stdin);
		gets(V[I].NOMBRE);
		printf("Ingrese la fecha con formato DD-MM-AA: ");
		scanf("%d-%d-%d",&V[I].NACIM.DIA,&V[I].NACIM.MES,&V[I].NACIM.ANIO); //"NACIM" es una variable de tipo
		printf("Ingrese el promedio del alumno: ");                         //struct FECHA, por lo tanto contiene
		scanf("%f",&F);                                                     //los mismos campos de la misma
		V[I].PROM = F;
	}
}
void ordenar(struct ALUMNO V[], int TAM){
	struct ALUMNO AUX;
	int I,J;
	for(I=0;I<TAM-1;I++){
		for(J=0;J<TAM-1-I;J++){
			if(dias(V[J].NACIM)<dias(V[J+1].NACIM)){ //Invoco la función dias y le transfiero argumentos
				AUX = V[J]; 
				V[J] = V[J+1];
				V[J+1] = AUX;
			}
		}
	}
}
void imprimir(struct ALUMNO V[], int TAM){
	int I;
	for(I=0;I<TAM;I++){
		printf("\n%20s%10d%4d%4d%12.2f",V[I].NOMBRE,V[I].NACIM.DIA,V[I].NACIM.MES,V[I].NACIM.ANIO,V[I].PROM);
	}
}
unsigned int dias(struct FECHA DATE){
	long X;
	X = 365*DATE.ANIO + 31*DATE.MES + DATE.DIA;
	return X;
}
