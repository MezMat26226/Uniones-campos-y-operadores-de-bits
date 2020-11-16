#include<stdio.h>
/*Una uni�n es una variable de tipo estructura en la que todos sus campos comienzan en la misma direcci�n de
memoria, los campos comparten el area de almacenamiento*/
union UN{
	char A;        //Los campos se superponen
	short int B;   //El tama�o de la union es igual al tama�o del mayor de sus campos
	float C;       //Ahorro de memoria
};
struct STR{
	char A;
	short int B;
	float C;       //Este es el campo mayor, y es en donde se "solapan" los demas campos
};
main()
{
	union UN X;
	struct STR AUX;
	printf("\nIngrese un caracter: ");
	scanf("%c",&X.A);
	printf("\nIngrese un numero entero: ");
	scanf("%d",&X.B);
	printf("\nIngrese un numero con decimales: ");
	scanf("%f",&X.C);
	printf("\nTamanio de la union: %d",sizeof(X));
	printf("\nTamanio de la estructura: %d",sizeof(AUX));
	printf("\n Caracter: %c",X.A);
	printf("\n Entero: %d",X.B);
	printf("\n Flotante: %f",X.C);
}
