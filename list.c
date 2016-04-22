#include <memory.h>
#include "librerias.h"
#include <stdlib.h>

typedef struct tCell{   
int payload;
void *next;
} Cell;

Cell agregar (int numero, Cell *root){
Cell *nuevo_nodo; 
nuevo_nodo = (Cell*)malloc(sizeof(Cell)); 
nuevo_nodo->payload=numero; 
nuevo_nodo->next=NULL;
Cell *cursor = root;  
while (cursor->next !=NULL)   
cursor = (Cell*)cursor->next;
cursor->next = (void*)nuevo_nodo; 
return *root;
}

void imprimeLista(Cell *root){
while((root=((Cell*)root->next))!= NULL)
printf("%d ->",root -> payload);
}

Cell pop (Cell root) {/

Cell *cursor; 
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
	
	while (root->next!= NULL)
		root=root->next;
	
	pop (*root);
	
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
        	printf ("Dame número");
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