/*Pediremos los IDs (números) de alumnos de dos clases, álgebra y análisis. Queremos
mostrar a todos los alumnos comunes en las dos asignaturas. Estos alumnos se guarden
en un tercer arreglo y que sea el que se muestre. También indica el número de alumnos
que se repiten. Deberá realizar una función o procedimiento que recibirá por parámetros
los 3 arreglos para realizar la comparación, y fuera del procedimiento o función
mostrará el resultado que se guardó en el 3er arreglo. */
#include <stdio.h>
int  comparacion(int *numAlgebra,int *numAnalisis,int *arreglo3, int tam){
	int i,comun=0,j;
	/*arreglo anidados*/
  	for(i = 0; i < tam; i++){
    	for(j = 0; j < tam; j++){
         if (numAlgebra[i]==numAnalisis[j]){ /*compara si son iguales*/
        	printf ("---------------------------------- \n");
		printf ("HAY ALUMNOS EN COMUNES \n ");
		printf ("---------------------------------- \n");
            arreglo3[comun] = numAlgebra[i]; /*hago la copia del arreglo*/
           comun++;
              printf("%d \n", arreglo3[i]);
        }
    }
  }
  printf ("cantidad de alumnos repetidos: %d \n",comun+comun); /*puse comun+comun ya que si hay 1 par de alumnos en comun hay 4 numeros repetidos*/
	return *arreglo3;
}

int main (void){
	int numAlgebra[3],numAnalisis[3],i,arreglo3[3],*ptrB,*ptrC,*ptrD,cantAlu,cantidadTotal=0;
	ptrB = numAlgebra;
	ptrC=numAnalisis;
	ptrD=arreglo3;
	printf ("ingrese la cantidad de alumnos \n");
	scanf ("%d", &cantAlu);
	for (i=0;i<cantAlu;i++){	
		numAlgebra[i]=0;
		numAnalisis[i]=0;
		}
	for (i=0;i<cantAlu;i++){
		printf ("ingrese numero de los alumnos de la clase de algebra \n");
		scanf ("%d", &numAlgebra[i]);
		if (numAlgebra[i]<0){
			printf ("VALOR INCORRECTO DEBE INGRESAR UN NUMERO MAYOR A 0");
		}
		printf ("ingrese numero de los alumnos de la clase de analisis\n");
		scanf ("%d", &numAnalisis[i]);
		if (numAnalisis[i]<0){
		printf ("VALOR INCORRECTO DEBE INGRESAR UN NUMERO MAYOR A 0");
		}
	}
		comparacion(ptrB,ptrC,ptrD, cantAlu);
		return 0;
}
