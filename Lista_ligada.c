#include <memory.h>
#include "librerias.h"
#include <stdlib.h>

typedef struct tCell{   //tcell es el nombre de la estructura con * son variables dinamicas y deben de llevar la flecha
int payload;
void *next;
} Cell;

void imprimirnodo (Cell *root) {
	int i;
	int index;
	i=0;
	int valor;
	Cell *cursor = root;
	printf("¿Que numero de nodo quieres ver?");
	scanf("%d", &index);
	while ( i != index) {
		i = i + 1;
		cursor = (Cell*) cursor->next;
	}
	valor=cursor->payload; 
	printf("El valor del nodo es: %d", valor);
	
}




void reemplazar (Cell *root) {
	int i;
	int index;
	i=1;
	int nuevovalor;
	Cell *cursor = root;
	printf("¿Que numero de nodo quieres reemplazar?");
	scanf("%d", &index);
	while ( i != index) {
		i = i + 1;
		cursor = (Cell*) cursor->next;
	}
	printf("¿Cual es el nuevo valor para el nodo?\n");
	scanf("%d", &nuevovalor);
	cursor->payload = nuevovalor;

	
}

void borranodo (Cell *root){

	int nodo;
	int i;
	i = 1;

	Cell *cursor = root;
	Cell *cursor2 = root->next;
	printf("¿Que nodo quieres borrar?");
	scanf ("%d", &nodo);
	if (nodo==1) {
			//Cell *root = root->netx;
			//Cell *cursor = root;
			cursor = root->next;
			root = root->next;

	} else 
	{
			while (i != nodo)
			{
				cursor2=cursor;
				cursor=cursor->next;
				i=i+1;

			}
			if (cursor->next != NULL)
			{
				cursor2->next=cursor->next;
			} else 
			{
				cursor2->next=NULL;
			}
	}
}






Cell agregar (int numero, Cell *root){
Cell *nuevo_nodo; // crear una nueva variable 
nuevo_nodo = (Cell*)malloc(sizeof(Cell)); //malloc crea una variable para qeu se comporta con todo y es necesario un puntero
nuevo_nodo->payload=numero; // o tambien se escribe asi (*nuevo_nodo)playload=numero; 
nuevo_nodo->next=NULL;
// para una variable este vacia es ==NULL
Cell *cursor = root;  // hace que reconozc TODOS 
while (cursor->next !=NULL)  // todavia no llega a el final 
cursor = (Cell*)cursor->next;
cursor->next = (void*)nuevo_nodo; //aqui se agrega el uevo nodo hasta el final del cursor el final llega gracias a el while
        // es void porque el next es void y entonces el nuevo nodo se aplica un castig para que sea void 
//roo.next= malloc(sizeof(Cell)); //esto significa cómo crear un nodo 
//((Cell*))root.next)->payload=numero; 
return *root;
}

void imprimeLista(Cell *root){
//printf("%d", ((Cell*)root->next)->payload);
while((root=((Cell*)root->next))!= NULL)
printf("%d ->",root -> payload);
}
// POR CADA NODO UN FREE

//borro el ultimo --->
Cell pop (Cell root) {//pasa la lista entera //pop es una funcion 
//free debe de recibir un punterooo

Cell *cursor; //se tiene que mover el cursor hasta el final
cursor=&root;
while (((Cell*)cursor->next)->next != NULL){
	printf("%d", cursor->payload);
	cursor = (Cell*)cursor -> next;
}
printf("%d", cursor->payload);
free (cursor->next);
cursor -> next = NULL;
return root;
}

Cell *erase (Cell *root) {
	//Cell *cursor;
	//cursor=&root;
	while (root->next!= NULL)
		root=root->next;
	//	printf("%d", cursor->payload);
	//	cursor= (Cell*) cursor->next;	
	//}
	pop (*root);
	//printf("%d\n", cursor->payload);
	//free (cursor->next);
	//cursor -> next = NULL;
	return root;
}

int main (int argc, char* argv[]){
	Cell *root;
	root= (Cell*)malloc(sizeof(Cell));
	root->next=NULL;
	int opcion;
	int numero;
	while(opcion != 3) {
    	printf ("Dame opcion \n");
		scanf ("%d",&opcion);
	


		if (opcion == 0){
        	printf ("Dame numero");
			scanf ("%d",&numero);
			agregar (numero, root);
			
			}
		if (opcion == 2)
		{
       	 	pop(*root);
		}

		if (opcion == 1)
		{
        	imprimeLista(root);
		}
		if(opcion == 4)
		{
			imprimirnodo (root);
		}
		if (opcion == 5)
		{
			reemplazar (root);
		}
		if (opcion==6) {
			borranodo (root);
		}
	}
	if (opcion == 3) 
	{
	    erase(root);
	}

	}