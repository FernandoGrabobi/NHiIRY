/* . Realizar un algoritmo que permita cargar un arreglo A de 7 elementos, que permita
ingresar solo números enteros entre 1 y 10. Si el usuario ingresa mal el valor, el sistema
no puede continuar con el próximo hasta que el valor sea correcto. Luego de haber
cargado el arreglo A, el usuario deberá acceder a un procedimiento o función que le
permita duplicar los valores del arreglo A. Por último, y en otra función o
procedimiento, se deberá cargar un nuevo arreglo B, pero cada valor del nuevo arreglo,
deberá ser el triple del valor del arreglo A. En una última función o procedimiento,
mostrar los valores del A y los valores del arreglo B, este último en orden inverso al
cargado*/
#include <stdio.h>
void carteleria(int arregloA[7]){
	int i;
	for (i=0;i<7;i++){
		arregloA[i]=0;
	}
	for (i=0;i<7;i++){
		do {
			printf ("Cargue el arreglo con los valores\n");
			scanf ("%d",&arregloA[i]);
			if (arregloA[i]<1 || arregloA[i]>10){
				printf ("ERROR \n");
				printf ("porfavor ingrese un numero de 1 al 10 \n");
			}
		
		}
		while (arregloA[i]<1 ||arregloA[i]>10); /*este do lo uso para repetir la carteleria y cargar de nuevo el dato en caso q este mal ingresado*/
		
	}
	
}

int duplicados(int *arregloA,int tam, int duplicar){
	int i=0;	
	for (i=0;i<tam;i++){
		duplicar= arregloA[i] * arregloA[i];
	}
	return duplicar;
}


 void procedim2(int *arregloA,int *arregloB,int tam,int triple){
	int i=0;
	/*system ("cls");*/
	printf ("--Triple del arreglo A-- \n");
	
	for (i=0;i<tam;i++){
	 	triple = arregloA[i] *3;
	 	/*procedim2(arregloA,arregloB,3);*/
		printf ("el triple del arreglo A en la posicion:  %d  es: %d \n",i, triple);	
		arregloB[i]= triple;
		printf ("-------------------------------------\n");
		printf ("copia del arreglo A, al arreglo B \n");
		printf ("-------------------------------------\n");
		printf ("ARREGLO B en la posicion %d : es: %d \n", i,arregloB[i]);
			
		}
		
	}

void inverso(int *arregloB,int inverso){
	int i=0;
	for ( i=6; i>=0; i--){
		printf ("el inverso del arreglo B es:  %d \n",arregloB[i]);	 /*revisar*/
	}
		
}
int main (void){
	int arregloA[7],i,arregloB[7],*ptrA, *ptrB,duplicar,triple;
	carteleria(arregloA);
	
	ptrA= arregloA;
	ptrB= arregloB;

	duplicados(ptrA,7,2);
     procedim2(ptrA,ptrB,7,triple);
    	
	for (i=0;i<7;i++){
		
		arregloB[i]=0;
	}
	/*	for (i=0;i<7;i++){
		printf ("los valores del arreglo son : %d \n", arregloA[i]);
		/*carteleria(arregloA)
		duplicados(arregloA);
		
		funcion2(duplicar,arregloB);
		inverso(arregloB);
	} */
	printf("los valores duplicados del arreglo son: \n");
	duplicados(arregloA,7, duplicar);
    	printf("los valores triplicados para el arreglo B \n");
  
    	procedim2(ptrA, ptrB, 7,triple);
    	printf ("orden inverso del arreglo  B \n ");
	inverso(ptrB,inverso);
}
	

	

