#include <memory.h>
#include "librerias.h"
#include <stdlib.h>

typedef struct tCell{   //tcell es el nombre de la estructura con * son variables dinamicas y deben de llevar la flecha
int payload;
void *next;
} Cell;

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
	}
	if (opcion == 3) 
	{
	    erase(root);
	}

	}