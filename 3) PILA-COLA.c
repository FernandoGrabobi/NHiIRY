//3) Implementar las ABM de la pila usando la estructura de datos estática arreglo.
//a. Se inserta un dato a la vez
//b. El límite del arreglo es de 10 elementos
//c. Determinar una solución para cuando el arreglo esté completo
//d. Debe ser posible consultar el tope de la pila
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void inicializar(int arreglo[]){
    int i;
 for (i=0;i<10;i++){
    arreglo[i]=0;


    }
}
void empujar (int arreglo[]){
    int i;
    i=9;
    while(i>=0){
        if(arreglo[i]==0)
        printf(" INGRESE EL VALOR \n ");
        scanf ("%d", &arreglo[i]);
        printf(" A [%d] -> %d \n  ",i, arreglo[i]);
        break;
        i--;

    }
    printf("nuevo\n");
    for (i=0;i<10;i++){
       if(arreglo[i]!=0)
        printf(" A [%d] -> %d \n",i, arreglo[i]);
        else
            printf(" A [%d] -> 0 \n ",i );
    }

}
void eliminar(int arreglo[]){
 int i, j, aux[10], eliminar = 0;
 inicializar(aux);
 printf(" INGRESE EL VALOR \n ");
 scanf ("%d", &eliminar);

    for (i=9;i>=0;i--){

        if( arreglo[i] == eliminar)
        {
            arreglo[i] = arreglo[i+1];
            for(j=i; j<10;j++)
                arreglo[j] = arreglo[j+1];
            arreglo[j]=0;
        }

        printf(" A [%d] -> %d \n ",i, arreglo[i]);
    }


}
void mostrarTope(int arreglo[]){
int i=0;
   while(i<10){
        if(arreglo[i]!=0)
            printf("TOPE: %d",arreglo[i]);
    break;
   }
}
int main (void){
    int arreglo[10], op, continuar, i=0;
    int *ptrArreglo;
    ptrArreglo = &arreglo;
    inicializar(ptrArreglo); //le paso el arreglo por que si pongo el ptr se pierde el valor
    for (i=0;i<10;i++){
        printf("%d",arreglo[i]);
    }
   do {
        printf(" ---- ESTRUCTURA DE PILA ---- \n 1-  EMPUJAR UN ELEMENTO DETRO DE LA PILA\n 2- SACAR UN ELEMENTO DE LA PILA\n 3-MOSTRAR TOPE\n 4- SALIR\nOPCION:");
        scanf("%d", &op);
        switch(op){
        case 1:
            empujar (ptrArreglo);
            break;
        case 2:
           eliminar(ptrArreglo);
            break;
      case 3:

     mostrarTope(ptrArreglo);
            break;
        case 4:
            printf("FIN");
            return 0;
            break;
        }//fin del sw
        printf ("\n PARA CONTINUAR PRESIONE 1 SI NO CUALQUIER NUMERO \n CONTINUAR:");
        scanf("%d", &continuar);
    }//fin del do
    while (continuar==1);


return 0;
}
