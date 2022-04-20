//1-Implementar el manejo parcial de impresiones de archivos de una impresora. Las operaciones posibles a realizar son:
//a. Ingresar un documento a imprimir, lo cual agrega un elemento a la cola de impresión.
//b. Ver listado de documentos a imprimir.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodoCola{
    char documento[50];
    struct nodoCola * ptrSiguiente;
};
typedef struct nodoCola NodoCola;
typedef NodoCola *ptrNodoCola;
//inserta un nodo al final de la cola
void empujar(ptrNodoCola *ptrCabeza,ptrNodoCola *ptrTalon,char  arreglo[]){
    int i;
    fflush(stdin);
    printf ("INGRESE EL DOCUMENTO \n");
    gets(arreglo);
    ptrNodoCola ptrNuevo; //APUNTADOR AL NUEVO NODO
    ptrNuevo = malloc(sizeof(NodoCola));
    if(ptrNuevo != NULL){
        for (i=0;i<50;i++){
          ptrNuevo->documento[i] = arreglo[i];
        }
        ptrNuevo->ptrSiguiente = NULL;
        //si esta vacia inserta el nodo en la cabeza
    if (estaVacia(*ptrCabeza)){
            *ptrCabeza=ptrNuevo;
    }
    else{
    (*ptrTalon)->ptrSiguiente= ptrNuevo;

    }
    *ptrTalon= ptrNuevo;
    }//fin del if
    else
    printf("%s NO SE INSERTO, MEMORIA INSUFUCIENTE",arreglo);
}//fin de la funcion
char sacar(ptrNodoCola *ptrCabeza,ptrNodoCola *ptrTalon)
{
    if (*ptrCabeza!=NULL){
       ptrNodoCola ptrTemporal; //APUNTADOR A NODO TEMPORAL
    char valorEliminado;

    valorEliminado = (*ptrCabeza)->documento;
    ptrTemporal= (*ptrCabeza);
    (*ptrCabeza) = (*ptrCabeza)->ptrSiguiente;
    if (*ptrCabeza==NULL){
        *ptrTalon=NULL;
    }
     printf ("VALOR ELIMINADO ES: %s",ptrTemporal );
    free(ptrTemporal);
    return valorEliminado;
    }
    else{
        printf ("\n NO SE PUEDE ELIMINAR NADA LA LISTA ESTA VACIA \n");
        return 0;
    }

}

void imprimeCola(ptrNodoCola ptrActual){

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

int estaVacia(ptrNodoCola ptrCabeza) //DEVUELTE 1 SI ESTA VACIAS O 0 CERO LO CONTRARIO
{
    return ptrCabeza == NULL;
}


int main(void)
{
    char arreglo[50],*ptrArreglo;
    int i=0,continuar;
    ptrArreglo= &arreglo;
    for(i=0; i<50; i++)
        arreglo[i] = NULL;
    NodoCola *ptrCabeza = NULL; //define el nodoCola
    NodoCola *ptrTalon = NULL; //define el nodoCola
    int op=0;
    do {
        printf(" ---- ESTRUCTURA DE PILA ---- \n 1-  EMPUJAR UN ELEMENTO DETRO DE LA PILA\n 2- SACAR UN ELEMENTO DE LA PILA\n 3- SALIR\nOPCION:");
    scanf("%d", &op);
    switch(op)
    {
    case 1:
        empujar(&ptrCabeza,&ptrTalon,&ptrArreglo);
        imprimeCola(ptrCabeza);
        break;
    case 2:
        printf ("LISTA ANTES DE ELIMINAR \n");
        imprimeCola(ptrCabeza);
        sacar(&ptrCabeza,&ptrTalon);
        imprimeCola(ptrCabeza);
        break;
    case 3:
        return 0;
        break;
    }//fin del sw
    printf ("\n PARA CONTINUAR PRESIONE 1 SI NO CUALQUIER NUMERO \n CONTINUAR:");
    scanf("%d", &continuar);
    }//fin del do
    while (continuar==1);


return 0;

}
