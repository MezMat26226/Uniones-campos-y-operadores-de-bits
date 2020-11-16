#include<stdio.h>
#include<string.h>
#define N 50
typedef struct{
	char eng[N];
	char esp[N];
	int lleno;
}traductor;
traductor trad[N];
void vacio();
void aniadir();
void traducir();
void tradu(int op);      
int main(){
	int op;
	char key;
	vacio();
	do{
		do{
			printf("Eligi que queres hacer: \n");
			printf("(1) Aniadir palabras al traductor.\n");
			printf("(2) Buscar traduccion de una palabra.\n");
			scanf("%d",&op);
		}while(op<1||op>2);
		switch(op){
			case 1:
				aniadir();
				break;
			case 2:
				traducir();
				break;	
		}
		printf("Introduce si deseas realizar otra operacion: (S/N)");
		scanf("%c",&key);
	}while(key=='s'||key=='S');
	printf("\n\tFin del programa.\n");
	return 0;
}
void vacio(){
	int i;
	for(i=0;i<N;i++){
		trad[i].lleno = 0;
	}
}
void aniadir(){
	int i,aux=0;
	for(i=0;i<N&&aux==0;i++){
		if(trad[i].lleno==0){
			printf("Introduce la palabra en ingles: ");
			fflush(stdin);
			gets(trad[i].eng);
			printf("Introduce la palabra en espaniol: ");
			fflush(stdin);
			gets(trad[i].esp);
			trad[i].lleno = 1;
			aux = 1;
		}
	}
}
void traducir(){
	int op;
	do{
			printf("Eligi que queres hacer: \n");
			printf("(1) Traducir de ingles a espaniol.\n");
			printf("(2) Traducir de espaniol a ingles.\n");
			scanf("%d",&op);
		}while(op<1||op>2);
		switch(op){
			case 1:
				tradu(op);
				break;
			case 2:
				tradu(op);
				break;	
		};
}
void tradu(int op){
	int i,j,k=0;
	char aux[N];
	printf("Introduce la palabra que deseas buscar: ");
	fflush(stdin);
	gets(aux);
	if(op==1){
		for(i=0;i<N&&k==0;i++){
			j = strcmp(aux,trad[i].eng);
			if(j==0){
				printf("La traduccion de %s es: %s.\n",trad[i].eng,trad[i].esp);
				k = 1;
			}
		}
	}
	else{
		for(i=0;i<N&&k==0;i++){
			j = strcmp(aux,trad[i].esp);
			if(j==0){
				printf("La traduccion de %s es: %s.\n",trad[i].esp,trad[i].eng);
				k = 1;
			}
		}
	}
}
