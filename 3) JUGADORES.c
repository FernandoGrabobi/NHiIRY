//Crear un programa que permita almacenar los nombres, edades, y alturas, de
//jugadores de básquet creando una lista enlazada. Posteriormente se presentará un
//menú que permita:
//a. ABM de jugadores.
//b. Listar los nombres de los jugadores.
//c. Listar las alturas de los jugadores.
//d. Listar las edades de los jugadores.
//e. Buscar un jugador por su nombre y presentar su altura y su edad.
//f. Indicar el nombre y edad del jugador más alto.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct nodoLista{
    float altura;
    char nombre[20];
    int edad;

    struct nodoLista *ptrSiguiente;
};
typedef struct nodoLista  Nodolista;
typedef  Nodolista *ptrNodolista; //nodolista TIPO Puntero
void carteleria(){
printf("--------------------------------------\n");
printf("1- AGREGAR NUEVO JUGADOR \n");
printf("2- ELIMINAR UN JUGADOR\n");
printf("3- MODIFICAR DATOS DE UN JUGADOR\n");
printf("4- BUSCAR JUGADOR POR SU ALTURA\n");
printf("5- JUGADOR MAS ALTO\n");
printf("6- LISTAR JUGADORES \n");
printf("--------------------------------------\n");
}//fin de la funcion

void pausa(){
system("pause");
system("CLS");
}//fin de la funcion


void nuevo(ptrNodolista *ptrS,int edad,char nom[],float altura){
    int i;
    ptrNodolista ptrNuevo;//Apunta al nuevo nodo
    ptrNodolista ptrActual;//Apunta al nodo actual
    ptrNodolista ptrAnterior;//Apunta al nodo Anterior

    ptrNuevo= malloc(sizeof(Nodolista));//Crea un nodo
    if(ptrNuevo!=NULL){//Condicion para saber que el espacio esta disponible
       (ptrNuevo)->edad=edad;//dato que usuario quiere incluir a la lista
       (ptrNuevo)->altura=altura;
        strcpy(ptrNuevo->nombre,nom);//2 cadenas de caracteres
       //for(i=0;i<20;i++){
         //   (ptrNuevo)->nombre[i]=nom[i];//Usar strcpy
   }
    (ptrNuevo) -> ptrSiguiente=NULL;//siempre va
    ptrAnterior= NULL;//siempre va
    ptrActual= (*ptrS);//siempre va
   while(ptrActual!=NULL &&  altura> (ptrActual)->altura){//insertar datos ordenados
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
int vacia(ptrNodolista ptrS){
return ptrS==NULL;
}//fin de la funcion
void mostrar(ptrNodolista ptrActual){
    if(ptrActual==NULL){
        printf("LA AGENDA ESTA VACIA \n");
    }
    else{
        printf("AGENDA:\n");
    while(ptrActual!=NULL){
        printf("-------------------------------------------\n");
        printf("NOMBRE: %s\n",ptrActual->nombre);
        printf("EDAD: %d \n",ptrActual->edad);
        printf("ALTURA: % f\n",ptrActual->altura);
        printf("-------------------------------------------\n\n");
        ptrActual=ptrActual->ptrSiguiente;
    }
    //printf("NULL\n");
    }
}//fin de la funcion
char eliminar(ptrNodolista *ptrS,char nom[]){
    ptrNodolista ptrTemporal;
    ptrNodolista ptrAnterior;
    ptrNodolista ptrActual;

    if(strcmp(nom,(*ptrS)->nombre)==0){
        ptrTemporal=*ptrS;
        *ptrS=(*ptrS)->ptrSiguiente;
        free(ptrTemporal);
        printf("SE ELIMINO EL JUGADOR: %s \n",nom);
        return nom;

    }
    else {
        ptrAnterior=*ptrS;
        ptrActual=(*ptrS)->ptrSiguiente;
        while(ptrActual!=NULL && strcmp(ptrActual->nombre,nom)!=0){
            ptrAnterior=ptrActual;
            ptrActual=ptrActual->ptrSiguiente;
        }
        if(ptrActual!=NULL){
            ptrTemporal=ptrActual;
            ptrAnterior->ptrSiguiente=ptrActual->ptrSiguiente;
            free(ptrTemporal);
            printf("SE ELIMINO EL JUGADOR: %s \n",nom);
            return nom;

        }
         else {
            printf("JUGADOR NO ENCONTRADO PARA ELIMINAR %s\n",nom);
        }
    }

}//fin de la funcion
void modificar(ptrNodolista ptrS, char nombre[]){
    int op,x;
    printf("ELIJA EL DATO QUE DESEA MODIFICAR DEL JUGADOR QUE INGRESO:  \n");
    printf("OPCION 1: NOMBRE \n");
    printf("OPCION 2: EDAD \n");
    printf("OPCION 3: ALTURA \n");
    scanf("%d", &op);
        switch(op){

case 1:
    if(strcmp(nombre,(ptrS)->nombre)==0){
        printf("JUGADOR:  %s ",ptrS->nombre);
        printf("\n NUEVO NOMBRE: ");
        fflush(stdin);
        gets(ptrS->nombre);
        }
    else {
        while(ptrS!=NULL && strcmp(ptrS->nombre,nombre)!=0){
            ptrS=ptrS->ptrSiguiente;
        }
        if(ptrS!=NULL){
        printf("MODIFICAR DATOS DEL JUGADOR %s\n NUEVO NOMBRE: ",ptrS->nombre);
        fflush(stdin);
        gets(ptrS->nombre);
        }
        else {
            printf("NO SE ENCONTRO EL JUGADOR INGRESADO: %s\n",nombre);
        }
    }
    break;
case 2:
        printf("JUGADOR:  %s ",ptrS->nombre);
        if(strcmp(nombre,(ptrS)->nombre)==0){
        printf("\n NUEVA EDAD: ");
        fflush(stdin);
        scanf("%d",&ptrS->edad);
        }
          else {
        while(ptrS!=NULL && strcmp(ptrS->nombre,nombre)!=0){
            ptrS=ptrS->ptrSiguiente;
        }
        if(ptrS!=NULL){
        printf("\n NUEVA EDAD: ");
        fflush(stdin); scanf("%d",&ptrS->edad);
        }
        else {
            printf("NO SE ENCONTRO EL JUGADOR INGRESADO: %s\n",nombre);
        }
        }
    break;
case 3:
        if(strcmp(nombre,(ptrS)->nombre)==0){
        printf("JUGADOR:  %s",ptrS->nombre);
        printf("\n NUEVA ALTURA: ");
        scanf("%f",&ptrS->altura);
        }
          else {
        while(ptrS!=NULL && strcmp(ptrS->nombre,nombre)!=0){
            ptrS=ptrS->ptrSiguiente;
        }
        if(ptrS!=NULL){
        printf("\n NUEVA ALTURA: ");
        scanf("%f",&ptrS->altura);
        }
        else {
            printf("NO SE ENCONTRO EL JUGADOR INGRESADO: %s\n",nombre);
        }
    }
    break;
default:
    printf("OPCION INGRESADA INCORRECTA , VUELVA A INTENTARLO \n");
    modificar(ptrS,nombre);
    }//fin del sw
}//fin de la funcion
void buscarLista(ptrNodolista ptrS, float altura){
    int encontrado=0; //falso =0
    //para recorrer necesitamos guiarnos con actual o inicial
    //cuando inicial llega igual a null no hay mas nodos q recorrer

     while (ptrS != NULL){
         if (ptrS->altura == altura){//usar strcmp para comprarar las dos cadenas si da 0 es verdadero
            encontrado=1;//como lo encontro es verdadero=1
            printf ("ALTURA ENCONTRADA!!! %f \n", altura);
            printf ("ESTE JUGADOR PRESENTA EL NOMBRE:  %s \n Y EDAD: %d\n", ptrS->nombre,ptrS->edad);
            break;
        }
        ptrS= ptrS->ptrSiguiente; //como no se encontro que es igual avanza una posicion mas
        //nuevamente regresa al while
        }

    if (encontrado != 1){
    printf("JUGADOR CON LA ALTURA:  %f NO ENCONTRADO \n",altura );
    }
}//fin de la funcion
void masAlto(ptrNodolista ptrS){ //busca la mayor altura y muestra datos
    ptrNodolista ptrAlto;
    int alto=0;
    ptrAlto=malloc(sizeof(ptrNodolista));//se crea el nuevo puntero
    while(ptrS!=NULL){
        if(ptrS->altura > alto){
            alto=ptrS->altura;
            ptrAlto=ptrS;
    }
    ptrS=ptrS->ptrSiguiente;
    }
    printf("JUGADOR MAS ALTO MIDE: %f cm\n NOMBRE : %s\n EDAD: %d \n",ptrAlto->altura,ptrAlto->nombre,ptrAlto->edad);
}//fin de la funcion
void listar(ptrNodolista ptrS, int opcion){
    while(ptrS!=NULL){
    switch(opcion){
        case 1:
            printf("-%s\n",ptrS->nombre);
            break;
        case 2:
            printf("-%.0f cm\n",ptrS->altura);
            break;
        case 3:
            printf("-%d años\n",ptrS->edad);
            break;
    }
    ptrS=ptrS->ptrSiguiente;
    }
}
int main (void){
    ptrNodolista ptrInicial=NULL;
    int op,edad,x,opcion;
    float altura;
    char nombre[20],nom[20];
    do{
    carteleria();
    scanf("%d", &op);
    switch(op){
    case 1:
            printf("\n INGRESE EL NOMBRE :");
            fflush(stdin);
            gets(nombre);
            printf("\nINGRESE LA ALTURA :");
            scanf("%f",&altura);
            printf("INGRESE LA EDAD:");
            scanf("%d",&edad);
            nuevo(&ptrInicial,edad,nombre,altura);
            mostrar(ptrInicial);
            pausa();
    break;
    case 2:
    //eliminar
            if(!vacia(ptrInicial)){
            printf("INGRESE EL NOMBRE DEL JUGADOR QUE DESEA ELIMINAR-->");
            fflush(stdin);
            gets(nom);
            printf("\n");
            eliminar(&ptrInicial, nom);
            }
            else {
            printf("NO HAY NINGUN JUGADOR CARGADO PARA ELIMINAR \n");
            }
            pausa();
    break;
    case 3:
    //modificacion
            if(ptrInicial==NULL){
            printf("NO HAY NINGUN JUGADOR CARGADO PARA MODIFICAR \n");
            }
            else {
            printf("NOMBRE DEL JUGADOR QUE DESEA MODIFICAR: ");
            fflush(stdin); gets(nombre);
            modificar(ptrInicial,nombre);
            }
            pausa();

    break;
    case 4:
    //busqueda
            if(ptrInicial==NULL){
            printf("NO HAY NINGUN JUGADOR CARGADO PARA LA BUSQUEDA \n");
            }
            else {
            printf("ALTURA DEL JUGADOR QUE DESEA BUSCAR: ");
            scanf("%f",&altura);
            buscarLista(ptrInicial,altura);
            }

            pausa();

    break;
    case 5:
    //jugador mas alto
            if(ptrInicial==NULL){
            printf("NO HAY NINGUN JUGADOR CARGADO PARA MOSTRAR AL MAS ALTO \n");
            }
            else {
            masAlto(ptrInicial);
            }
             pausa();
    break;
    case 6:
        //listar jugadores
         printf("LISTAR : \n SELECCIONE DATO QUE DESEA VER \n 1- NOMBRES \n 2- ALTURAS \n 3- EDADES \n");
                do{
                scanf("%d",&opcion);
                if(opcion<1 || opcion>3){
                 printf("OPCION INCORRECTA, INTENTELO NUEVAMENTE \n \n OPCIONES:");}
                } while(opcion<1 || opcion>3);
                if(opcion==1){printf("LISTAR NOMBRES: \n");
                } else{
                    if(opcion==2){
                    printf("LISTAR ALTURAS: \n");
                    }
                    else{printf("LISTAR EDADES: \n");
                    }
                }
                listar(ptrInicial,opcion);
                 pausa();
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
}//fin de main
