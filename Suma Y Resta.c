//ingresar 2 elementos a la listas, sumarlas restarlas y mostrarlas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct nodoLista{
    int elemento1;
    int elemento2;
    int suma;
    int resta;

    struct nodoLista *ptrSiguiente;
};
typedef struct nodoLista  Nodolista;
typedef  Nodolista *ptrNodolista;

void nuevo(ptrNodolista *ptrS,int elemento1,int elemento2,int suma, int resta){
    int i;
    ptrNodolista ptrNuevo;//Apunta al nuevo nodo
    ptrNodolista ptrActual;//Apunta al nodo actual
    ptrNodolista ptrAnterior;//Apunta al nodo Anterior

    ptrNuevo= malloc(sizeof(Nodolista));//Crea un nodo
    if(ptrNuevo!=NULL){//Condicion para saber que el espacio esta disponible
       (ptrNuevo)->elemento1=elemento1;//dato que usuario quiere incluir a la lista
       (ptrNuevo)->elemento2=elemento2;
       (ptrNuevo)->suma=suma;
       (ptrNuevo)->resta=resta;
   }
    (ptrNuevo) -> ptrSiguiente=NULL;//siempre va
    ptrAnterior= NULL;//siempre va
    ptrActual= (*ptrS);//siempre va
   while(ptrActual!=NULL &&  elemento1> (ptrActual)->elemento1){//lo hago con altura para que despues pueda mostrar el jugador mas alto
        ptrAnterior = ptrActual;
        ptrActual = (ptrActual)->ptrSiguiente;
   }
   if(ptrAnterior == NULL){
        (ptrNuevo)->ptrSiguiente= (*ptrS);
        (*ptrS) = ptrNuevo;
   }
   else{
        (ptrAnterior)->ptrSiguiente=ptrNuevo;
        (ptrNuevo)->ptrSiguiente=ptrActual;
   }
   //else{
    //printf("MEMORIA INSUFICIENTE NO SE INSERTO : %.0f. \n",altura);
   //}
}//fin de la funcion

void mostrar(ptrNodolista ptrActual){
if(ptrActual==NULL){
    printf("NO HAY NUMEROS DISPONIBLES \n");
}
else{
    printf("NUMEROS:\n");
    while(ptrActual!=NULL){
printf("-------------------------------------------\n");
        printf("NUMERO 1 : %d \n",ptrActual->elemento1);
        printf("NUMERO 2: %d\n",ptrActual->elemento2);
        printf("SUMA DE ELLOS: %d \n",ptrActual->suma);
        printf("RESTA DE ELLOS: %d \n",ptrActual->resta);
printf("-------------------------------------------\n\n");
        ptrActual=ptrActual->ptrSiguiente;
    }
    //printf("NULL\n");
}
}//fin de la funcion
int sumaElementos(ptrNodolista *ptrS,int elemento1, int elemento2,int suma){

          (*ptrS)->suma = (*ptrS)->elemento1 + (*ptrS)->elemento2;
          printf("la suma de los dos elementos es %d:",  (*ptrS)->suma);

            return (*ptrS)->suma;

}
int restaElementos(ptrNodolista *ptrS,int elemento1, int elemento2,int resta){

            if ( (*ptrS)->elemento1 > (*ptrS)->elemento2){
                 (*ptrS)->resta = (*ptrS)->elemento1 - (*ptrS)->elemento2;
                printf("la resta de los dos elementos es %d:",  (*ptrS)->resta);
            }
            else {
                (*ptrS)->resta = (*ptrS)->elemento2 - (*ptrS)->elemento1;
                printf("la resta de los dos elementos es %d:",  (*ptrS)->resta);
            }

    return (*ptrS)->resta;


}
int main (void){
 ptrNodolista ptrInicial=NULL;
    int op,elemento1,elemento2,x,suma,resta;

    do{
    printf("elija una opcion\n");
    printf("1- cargar elementos \n");
    printf("2-sumarlos \n");
    printf("3-restarlos \n");
    printf("4-mostrarlos \n");
    scanf("%d",&op);
    switch(op){
    case 1:
            printf("\n INGRESE 1 elemento :");
            scanf("%d",&elemento1);;
            printf("\nINGRESE 2 elemento  :");
            scanf("%d",&elemento2);

            nuevo(&ptrInicial,elemento1,elemento2,suma,resta);



    break;
    case 2:
     printf("suma de elementos \n ");
    sumaElementos(&ptrInicial,elemento1,elemento2,suma);


    break;
    case 3:
        printf("resta de elementos \n ");
    restaElementos(&ptrInicial,elemento1,elemento2,resta);

        break;
    case 4:
        printf("LISTA: \n");
        mostrar(ptrInicial);
        break;

    default:
        printf ("OPCION INCORRECTA VUELVA A INGRESARLA \n");
        main ();
    break;
    }//fin switch
    printf ("PARA CONTINUAR PRESIONE 0 \n DE CASO CONTRARIO PARA FINALIZAR OTRO NUMERO \n");
    scanf ("%d", &x);
    }//fin del do

    while (x==0);

    return 0;


}



