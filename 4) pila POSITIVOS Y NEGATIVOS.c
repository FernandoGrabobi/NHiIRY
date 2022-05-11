//Dada una pila P de números enteros y un valor entero X, se desea implementar una
//operación que cambie de signo todos los elementos de la pila P.
//Luego deberá verificar si todos los valores de la pila son positivos.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct nodoPila {
int dato;
struct nodoPila *ptrSiguiente; //apuntador a nodoPila
};
typedef struct nodoPila NodoPila; //sinonimo de la estructura nodoPila
typedef NodoPila *ptrNodoPila; //sinonimo para NodoPila
//prototipos



void empujar(ptrNodoPila *ptrCima, int valor){
    ptrNodoPila ptrNuevo; //apuntador al nuevo nodo
    ptrNuevo= malloc (sizeof(NodoPila)); //creo un nuevo nodo
    //INSERTAR UN NOdo EN LA CIMA DE LA PILA
    if (ptrNuevo!=NULL){ //si el nodo nuevo es distinto de nulo
        ptrNuevo->dato= valor; //al nuevo nodo dato le damos el valor
        ptrNuevo->ptrSiguiente= *ptrCima; //y el nuevo apunta a la cima
        *ptrCima=ptrNuevo; //la cima se le asigna lo que contiene el nuevo
    }
    else {//no queda espacio disponible
        printf ("%d no se inserto, memoria insuficiente \n", valor);

    }
}//fin de empujar
void imprimePila(ptrNodoPila *ptrCima){
   ptrNodoPila ptrActual;
   ptrActual =(*ptrCima);
//si la pila esta vacia
if (ptrActual==NULL){
    printf ("LA PILA ESTA VACIA \n");
}
else {

    printf ("LA PILA ES --> ");//ver
    //mientras no sea el final de la pila
while (ptrActual !=NULL){
    if (ptrActual->dato<0 ){//si es negativo
        ptrActual->dato=abs(ptrActual->dato);
        printf ("%d ",ptrActual->dato);//valor absoluto para q muestre positivo

    }

    else {

       ptrActual->dato= ptrActual->dato*(-1);
       printf ("%d ", ptrActual->dato); //-1 para q lo muestre negativo

    }
    ptrActual = ptrActual->ptrSiguiente;
}
printf("\n NULL \n");
}

}//fin de la funcion imprimir
//devuelve 1 si esta vacia si no 0
int estaVacia(ptrNodoPila ptrCima){
return ptrCima==NULL;
}
int sacar (ptrNodoPila *ptrCima){

ptrNodoPila ptrTemp; //apuntador a un nodo temporal
int valorElim;
ptrTemp=*ptrCima; //temporal se le asigan lo de la cima
valorElim= (*ptrCima)->dato; //valor a eliminar la cima con dato
*ptrCima= (*ptrCima)->ptrSiguiente; //y cima se le asigna lo q contiene cima sigueinte
free(ptrTemp); //se libera la memoria del temporal

return valorElim;
}
//int estaVacia (ptrNodoPila ptrCima){
//return ptrCima==NULL;
//}
void verificar(ptrNodoPila ptrCima){
    ptrNodoPila ptrActual;
    ptrActual=ptrCima;
    int positivos=0,total=0;
    printf("SE MOSTRARAN LOS POSITIVOS EN SU FORMA DE SIGNO CAMBIADO \n");
    while(ptrActual!=NULL){
        total++;
        printf("dato %d \n",ptrActual->dato);
         if((ptrActual->dato)>=0){

              positivos++;

          }
        ptrActual = ptrActual->ptrSiguiente;
    }
    ptrActual=ptrCima;


     printf("CANTIDAD DE POSITIVOS %d:  \n",positivos);
     if (total==positivos) {
         printf("TODOS LOS ELEMENTOS SON POSITIVOS \n");
    }

    else
        printf(" NO TODOS LOS ELEMENTOS SON POSITIVOS \n");
}//fin de la funcion
int main (void){
ptrNodoPila ptrPila=NULL;//apunta AL TOPE de la pila
int valor, opcion,continuar;

do {
printf ("ELIJA UNA OPCION \n");
printf ("1-EMPUJAR VALOR DENTRO DE LA PILA \n");
printf ("2-SACAR EL VALOR DE LA PILA \n");
printf ("3-VERIFICAR VALOR  \n");
printf ("4- SALIR \n");
scanf ("%d", &opcion);
  switch (opcion){
case 1:
//empuja el valor dentro de la pila
printf ("INTRODUZCA UN VALOR A INSERTAR  \n");
scanf ("%d", &valor);
empujar (&ptrPila, valor);
imprimePila(&ptrPila);
break;
case 2:
   //sacar valor de la pila
   //si la pila no esta vacia
if (!estaVacia(ptrPila)){
        printf ("EL VALOR SACADO ES %d ", sacar(&ptrPila));
    }

    imprimePila(&ptrPila);
break;
case 3:
    //verificar si son los dos positivos
       verificar(ptrPila);
    break;

case 4:
    printf("FIN \n");


    break;


}//fin de switch
  printf ("\n PARA CONTINUAR PRESIONE 1 SI NO CUALQUIER NUMERO \n CONTINUAR:");
    scanf("%d", &continuar);

}//fin de while
 while (continuar==1);


}//fin de la funcion

