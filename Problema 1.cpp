#include <stdio.h>  //Se considera 0, como par
#include <stdlib.h>
#include <time.h>

int diagonal (int Tabla[5][7]){
	int sum = 0;
	for(int c = 0; c < 5; c++){
		for(int d = 0; d < 7; d++){
			if(c == d){
				sum += Tabla[c][d];
			}
		}
	}
	return sum;
}

int fila (int Tabla[5][7], int pos){ 
	int sum = 0;
	for(int e = 0; e < 7; e++){
		sum += Tabla[pos][e];
	}
	return sum;
}

int columna (int Tabla[5][7], int pos){
	int sum = 0;
	for(int f = 0; f < 5; f++){
		sum += Tabla[f][pos];
	}
	return sum;
}

int triangular (int Tabla[5][7], int ud){
	int sum = 0;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 7; j++){
			if(ud == 0)
				if(i < j)
					sum += Tabla[i][j];
			if(ud == 1)
				if(j < i)
					sum += Tabla[i][j];
		}
	}
	return sum;
}

int main(){
	int sum = 0;
	int Matriz[5][7];
	srand(time(NULL));
	
	for(int a = 0; a < 5; a++){
		for(int b = 0; b < 7; b++){
			Matriz[a][b] = rand() % 10;
			printf(" %d", Matriz[a][b]);
		}
		printf("\n");
	}
	printf("\nSuma de la diagonal: %d", diagonal(Matriz));
	printf("\nSuma de la fila %d: %d",0 , fila(Matriz, 0));
	printf("\nSuma de la columna %d: %d", 6, columna(Matriz, 6));
	printf("\n------------------------");
	for(int g = 0; g < 5; g++){
		if((g % 2) == 0){
			printf("\nSuma de la fila %d: %d",g , fila(Matriz, g));
			sum += fila(Matriz, g);
		}
	}
	printf("\nSuma de las filas pares: %d", sum);
	printf("\n------------------------");
	sum = 0;
	for(int h = 0; h < 7; h++){
		if((h % 2) == 1){
			printf("\nSuma de la columna %d: %d", h, columna(Matriz, h));
			sum += columna(Matriz, h);
		}
	}
	printf("\nSuma de las columnas impares: %d", sum);
	printf("\n------------------------");
	printf("\nSuma de la diagonal: %d", diagonal(Matriz));
	printf("\nSuma de la triangular superior: %d", (triangular(Matriz, 0) + diagonal(Matriz)));
	printf("\n------------------------");
	printf("\nSuma de la diagonal: %d", diagonal(Matriz));
	printf("\nSuma de la triangular inferior: %d", (triangular(Matriz, 1) + diagonal(Matriz)));
	
	
	return 0;
}
