#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int diagonal(int Tabla[3][3]){
	int sum = 0;
	for(int c = 0; c < 3; c++){
		for(int d = 0; d < 3; d++){
			if(c == d){
				sum += Tabla[c][d];
			}
		}
	}
	return sum;
}
int diagonalNT(int Tabla[3][3]){
	int sum = 0;
	int pos = 2;
	for(int c = 0; c < 3; c++){
		for(int d = 0; d < 3; d++){
			if(c == d){
				sum += Tabla[c][pos];
			}
			pos --;
		}
	}
	return sum;
}
int fila(int Tabla[3][3], int pos){ 
	int sum = 0;
	for(int e = 0; e < 3; e++){
		sum += Tabla[pos][e];
	}
	return sum;
}
int columna(int Tabla[3][3], int pos){
	int sum = 0;
	for(int f = 0; f < 3; f++){
		sum += Tabla[f][pos];
	}
	return sum;
}

int main(){
	int Matriz[3][3];
	int ans;
	int prim, ei = 1;
	
	for(int a = 0; a < 3; a++){
		for(int b = 0; b < 3; b++){
			printf("Posicion (%d, %d): ", a, b);
			scanf("%d", &ans);
			Matriz[a][b] = ans;
		}
	}
	printf("\n");
	for(int g = 0; g < 3; g++){
		for(int h = 0; h < 3; h++){
			printf(" %d", Matriz[g][h]);
		}
		printf("\n");
	} printf("\n");
	
	prim = fila(Matriz, 0);
	for(int i = 0; i < 3; i++){
		printf("\nSuma de la fila %d: %d",i+1 , fila(Matriz, i));
		if(prim != fila(Matriz, i)){
			ei = 0;
		}
	}
	for(int j = 0; j < 3; j++){
		printf("\nSuma de la columna %d: %d", j+1, columna(Matriz, j));
		if(prim != columna(Matriz, j)){
			ei = 0;
		}
	}
	printf("\nSuma de la diagonal: %d", diagonal(Matriz));
	if(prim != diagonal(Matriz)){
		ei = 0;
	}
	printf("\nSuma de la diagonal secundaria: %d", diagonalNT(Matriz));
	if(prim != diagonalNT(Matriz)){
		ei = 0;
	}
	if(ei == 1){
		printf("\nLa matriz es magica");
	}else{
		printf("\nLa matriz NO es magica");
	}
	
	return 0;
	}
