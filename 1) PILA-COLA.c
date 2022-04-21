//1-Implementar el manejo parcial de impresiones de archivos de una impresora. Las operaciones posibles a realizar son:
//a. Ingresar un documento a imprimir, lo cual agrega un elemento a la cola de impresión.
//b. Ver listado de documentos a imprimir.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodoPila{
    char documento[50];
    struct nodoPila * ptrSiguiente;
};
typedef struct nodoPila NodoPila;
typedef NodoPila *ptrNodoPila;
void empujar(ptrNodoPila *ptrCima,char  arreglo[]){
    int i;
    fflush(stdin);
    printf ("INGRESE UN EL DOCUMENTO \n");
    gets(arreglo);
    ptrNodoPila ptrNuevo; //APUNTADOR AL NUEVO NODO
    ptrNuevo = malloc(sizeof(NodoPila));

    if(ptrNuevo != NULL)
    {

        for (i=0;i<50;i++){
          ptrNuevo->documento[i] = arreglo[i];
        }
        ptrNuevo->ptrSiguiente = (*ptrCima);
        *ptrCima = ptrNuevo;
    }
    else
        printf("%s NO SE INSERTO, MEMORIA INSUFUCIENTE",arreglo);
}
int sacar (ptrNodoPila *ptrCima)
{
    if (*ptrCima!=NULL){
       ptrNodoPila ptrTemporal; //APUNTADOR A NODO TEMPORAL
    char valorEliminado;

    ptrTemporal = *ptrCima;
    valorEliminado = (*ptrCima)->documento;
    (*ptrCima) = (*ptrCima)->ptrSiguiente;
     printf ("VALOR ELIMINADO ES: %s",ptrTemporal );
    free(ptrTemporal);


    return valorEliminado;
    }
    else{
        printf ("\n NO SE PUEDE ELIMINAR NADA LA LISTA ESTA VACIA \n");
        return 0;
    }

}

void imprimePila(ptrNodoPila ptrActual){

    if(ptrActual == NULL)
    {
        printf("IMPRESION DE PILA: VACIA\n");
    }
    else
    {
        printf ("LA PILA ES ");
        while (ptrActual != NULL) //MIENTRAS NO SEA EL FINAL DE LA PILA
        {
            printf("-> %s ", ptrActual->documento);

            ptrActual = ptrActual->ptrSiguiente;
        }
    }
}

int pilaVacia(ptrNodoPila ptrCima) //DEVUELTE 1 SI ESTA VACIAS O 0 CERO LO CONTRARIO
{
    return ptrCima == NULL;
}


int main(void)
{
    char arreglo[50],*ptrArreglo;
    int i=0,continuar;
    ptrArreglo= &arreglo;
    for(i=0; i<50; i++)
        arreglo[i] = NULL;
    ptrNodoPila *ptrCima = NULL; //define el punteroPila
    int op=0;
    do {
        printf(" ---- ESTRUCTURA DE PILA ---- \n 1-  EMPUJAR UN ELEMENTO DETRO DE LA PILA\n 2- SACAR UN ELEMENTO DE LA PILA\n 3-MOSTRAR ELEMENTOS\n 4- SALIR\nOPCION:");
    scanf("%d", &op);
    switch(op)
    {
    case 1:
        empujar(&ptrCima,&ptrArreglo);
        break;
    case 2:
        printf ("LISTA ANTES DE ELIMINAR \n");
        imprimePila(ptrCima);
        sacar(&ptrCima);
        imprimePila(ptrCima);
        break;
    case 3:
        imprimePila(ptrCima);
         break;
    case 4:
        return 0;
        break;


    }//fin del sw
    printf ("\n PARA CONTINUAR PRESIONE 1 SI NO CUALQUIER NUMERO \n CONTINUAR:");
    scanf("%d", &continuar);
    }//fin del do
    while (continuar==1);


return 0;

}
