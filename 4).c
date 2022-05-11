/*4. Hacer una funcion o procedimiento que reciba en un parámetro una matriz X de N filas
y M columnas, llena de números enteros, y retorne un arreglo A de M posiciones con
la suma de cada columna */
#include <stdio.h>
#include <stdlib.h>
void inicializoMat(int matrizX[][2], int tam){
	int i, j;
		 for (i=0; i<tam;i++ ) {
		 	for (j=0;j<tam;j++){
		 		matrizX[i][j]=0;
			 }
         } 
}
int  matrizLlena(int matrizX[][2], int tam){
	int i=0,j=0,suma=0,suma1=0,arregloAux[2];
	for (i=0;i<tam;i++ ) {
		 	for (j=0;j<tam;j++){
		 		printf ("los valores de la matriz fila :  %d  columna:  %d valor: %d \n",i,j,matrizX[i][j]);
		 			
			}
     } 
	
     for (j=0;j<tam;j++){
     			suma+=matrizX[0][j];	
				suma1+=matrizX[1][j];
		}
		printf ("los valores sumados de la columna: %d \n",suma);
		printf ("los valores sumados de la columna: %d \n",suma1);
		arregloAux[i]=suma;
		printf ("posicion 0 ,arreglo auxiliar %d \n ", arregloAux[i]);
		arregloAux[i]=suma1;
		printf ("posicion 1 ,arreglo auxiliar %d \n ", arregloAux[i]);
		
		
	
     return arregloAux[i];
}
int main (void){
	int matrizX[2][2],i,j, *ptrA,tam;
	ptrA=&matrizX;
   inicializoMat (ptrA,2); 
   for(i=0;i<2;i++){
    	for(j=0;j<2;j++){
      	printf(" valores inicializados %d \n",matrizX[i][j]);
    	}
	}
    	for(i=0;i<2;i++){
    	for(j=0;j<2;j++){
     	printf ("profavor llene la matriz \n");
   		scanf ("%d",&matrizX[i][j]); 
    	}  
	}
   matrizLlena(ptrA, 2);
    
     
	
	return 0;
}

