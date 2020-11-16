/*Macro de ordenamiento*/
#include<stdio.h>
#define IMPRIMIR(X,T) for(I=0;I<T;I++)\
						{printf("\n%d",X[I]);}
#define ORDENAR(X,T)  for(I=0;I<T-1;I++)\
						for(J=0;J<T-1-I;J++)\
							if(X[J]<X[J+1]){\
								AUX=X[J+1];\
								X[J+1]=X[J];\
								X[J]=AUX;}
int main()
{
	int VEC[]={23,56,78,12,54,192,234,11,98,102};
	int I,J,AUX;
	IMPRIMIR(VEC,10);
	printf("\n VECTOR ORDENADO.\n"); 
	ORDENAR(VEC,10);
	IMPRIMIR(VEC,10);
}
