#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct nodoLista{
    double telefono;
    char nombre[20];
    char correo[20];
    struct nodoLista *ptrSiguiente;
};

typedef struct nodoLista  Nodolista;
typedef  Nodolista *ptrNodolista; //nodolista TIPO Puntero

void nuevo(ptrNodolista *ptrS,double numero,char nom[],char mail[]){
    int i;
ptrNodolista ptrNuevo;//Apunta al nuevo nodo
ptrNodolista ptrActual;//Apunta al nodo actual
ptrNodolista ptrAnterior;//Apunta al nodo Anterior

ptrNuevo= malloc(sizeof(Nodolista));//Crea un nodo
if(ptrNuevo!=NULL){//Condicion para saber que el espacio esta disponible
   (ptrNuevo)->telefono=numero;
   for(i=0;i<20;i++){
        (ptrNuevo)->nombre[i]=nom[i];
        (ptrNuevo)->correo[i]=mail[i];//Usar strcpy
   }
   (ptrNuevo) -> ptrSiguiente=NULL;//siempre va
   ptrAnterior= NULL;//siempre va
   ptrActual= (*ptrS);//siempre va
   while(ptrActual!=NULL && numero > (ptrActual)->telefono){
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
}
else{
    printf("MEMORIA INSUFICIENTE NO SE INSERTO : %.0f. \n",numero);
}
}

int eliminar(ptrNodolista *ptrS,double numero){
ptrNodolista ptrActual;//Apunta al nodo actual
ptrNodolista ptrAnterior;//Apunta al nodo Anterior
ptrNodolista ptrTemporal;//Apunta a un nodo temporal
if(numero== (*ptrS)->telefono){
    ptrTemporal= *ptrS;
    *ptrS= (*ptrS)->ptrSiguiente;//Separa el nodo
    free(ptrTemporal);
    return numero;
}
else{
    ptrAnterior= *ptrS;
    ptrActual= (*ptrS)->ptrSiguiente;

    while(ptrActual!=NULL && (ptrActual)->telefono!=numero){
        ptrAnterior=ptrActual;
        ptrActual=(ptrActual)->ptrSiguiente;
    }
    if(ptrActual!=NULL){
        ptrTemporal=ptrActual;
        (ptrAnterior)->ptrSiguiente= (ptrActual)->ptrSiguiente;
        free(ptrTemporal);
        return numero;
    }
}
return 0;
}
int vacia(ptrNodolista ptrS){
return ptrS==NULL;
}
void mostrar(ptrNodolista ptrActual){
if(ptrActual==NULL){
    printf("LA AGENDA ESTA VACIA \n");
}
else{
    printf("AGENDA:\n");
    while(ptrActual!=NULL){
printf("-------------------------------------------\n");
        printf("NUMERO: %.lf \n",ptrActual->telefono);
        printf("NOMBRE: %s\n",ptrActual->nombre);
        printf("CORREO ELECTRONICO: %s\n",ptrActual->correo);
printf("-------------------------------------------\n\n");
        ptrActual=ptrActual->ptrSiguiente;
    }
    //printf("NULL\n");
}
}

void carteleria(){
printf("--------------------------------------\n");
printf("1-AGREGAR AMIGO\n");
printf("2- ELIMINAR AMIGO\n");
printf("3- MOSTRAR AGENDA\n");
printf("--------------------------------------\n");
}

void pausa(){
system("pause");
system("CLS");
}

int main()
{
    ptrNodolista ptrInicial=NULL;
    int menu,x;
    double numero=0;
    char nom[20],email[20];

do{
carteleria();
scanf("%d",&menu);
switch(menu){
    case 1:
        printf("INGRESE EL NUMERO DE TELEFONO:");
        scanf("%lf",&numero);
        printf("\n INGRESE EL NOMBRE :");
        fflush(stdin);
        gets(nom);
        printf("\nINGRESE EL CORREO ELECTRONICO:");
        fflush(stdin);
        gets(email);
        nuevo(&ptrInicial,numero,nom,email);
        mostrar(ptrInicial);
        pausa();
    break;
    case 2:
        if(!vacia(ptrInicial)){
            printf("INGRESE EL NUMERO QUE DESEA ELIMINAR-->");
            scanf("%lf",&numero);
            printf("\n");
            if(eliminar(&ptrInicial,numero)){
                printf("NUMERO: %.0f ELIMINADO \n",numero);
                mostrar(ptrInicial);
            }
            else{
                printf("NUMERO INGRESADO NO EXISTENTE\n");
            }
        }
        pausa();
    break;
    case 3:
        mostrar(ptrInicial);
        pausa();
    break;
    }
    printf ("PARA CONTINUAR PRESIONES 0 \n DE CASO CONTRARIO PARA FINALIZAR OTRO NUMERO \n");
    scanf ("%d", &x);
}//final de do
while (x==0);

}
