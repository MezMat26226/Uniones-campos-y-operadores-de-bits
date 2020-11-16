#include<stdio.h>
#include<string.h>
#define N 50
typedef struct{
	char nombre_lib[N];
	char autor[N];
	int lleno_lib;
}libro; //Creo la variable estructura
typedef struct{
	char nombre_lib[N];
	libro lib [10]; //Ahora, de esa misma variables, creo 10 
	int lleno_bi;
}biblioteca;
biblioteca bi[3]; //Por ultimo, un vector de estructuras
void vacio();
void anadebi();
void anadelib();
void consulta();

int main(){
	int op;
	char key;
	vacio();
	do{
		do{
			printf("Elegi una opcion: \n");
			printf("(1) Aniadir una nueva biblioteca.\n");
			printf("(2) Aniadir un libro a una biblioteca.\n");
			printf("(3) Consultar un libro.\n");
			scanf("%d",&op);
		}while(op<1||op>3);
		switch(op){
			case 1:{
				anadebi();
				break;
			}
			case 2:{
				anadelib();
				break;
			}
			case 3:{
				consulta();
				break;
			}
		}
		printf("Queres realizar otra accion? (S/N)\n");
		fflush(stdin);
		scanf("%c",&key);
	}while(key=='S'||key=='s');
	printf("\tFin del programa.\n");
	return 0;
}
void vacio(){
	int i,j;
	for(i=0;i<3;i++){
		bi[i].lleno_bi = 0;
		for(j=0;j<10;j++){
			bi[i].lib[j].lleno_lib = 0;
		}
	}
}
void anadebi(){
	int i,aux=0;
	for(i=0;i<3&&aux==0;i++){
		if(bi[i].lleno_bi==0){
			printf("Introduce un nombre para la biblioteca: ");
			fflush(stdin);
			gets(bi[i].nombre_lib);
			bi[i].lleno_bi = 1;
			aux = 1;
		}
	}
	if(aux==0){
		printf("No queda ningun hueco libre para una nueva biblioteca.\n");
	}
}
void anadelib(){
	int i,op=0,aux=0;
	for(i=0;i<3;i++){
		if(bi[i].lleno_bi==1){
			printf("(%d)\t%s.\n",i,bi[i].nombre_lib);
		}
	}
	scanf("%d",&op);
	for(i=0;i<10&&aux==0;i++){
		if(bi[op].lib[i].lleno_lib==0){
			printf("Introduce el nombre del libro: ");
			fflush(stdin);
			gets(bi[op].lib[i].nombre_lib);
			printf("Introduce el nombre del autor: ");
			fflush(stdin);
			gets(bi[op].lib[i].autor);
			bi[op].lib[i].lleno_lib = 1;
			aux = 1;
		}
	}
}
void consulta(){
	int i,j,aux=1,op=0;
	char buscar[N];
	do{
		printf("Que deseas buscar: \n");
    	printf("(1) Nombre de un libro.\n");
    	printf("(2) Nombre de un autor.\n");
    	scanf("%d",&op);
	}while(op<1||op>2);
	switch(op){
		case 1:{
			printf("Introduce el nombre del libro: ");
			fflush(stdin);
			gets(buscar);
			for(i=0;i<3;i++){
				aux = 1;
				for(j=0;j<10;j++){
					aux = strcmp(buscar,bi[i].lib[j].nombre_lib);
					if(aux==0){
						printf("El libro %s se encuentra en la biblioteca %s.\n",buscar,bi[i].nombre_lib);
						printf("El autor del libro es %s.\n",bi[i].lib[j].autor);
					}
				}
			}
			break;
		}
		case 2:{
			printf("Introduce el nombre del autor: ");
			fflush(stdin);
			gets(buscar);
			for(i=0;i<3;i++){
				aux = 1;
				for(j=0;j<10;j++){
					aux = strcmp(buscar,bi[i].lib[j].nombre_lib);
					if(aux==0){
						printf("El libro %s se encuentra en la biblioteca %s.\n",bi[i].lib[j].nombre_lib,bi[i].nombre_lib);
					}
				}
			}
			break;
		}
	}
}
