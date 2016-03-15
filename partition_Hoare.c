#include "librerias.h"

int kSize=9;
//Funciones Principales 

void imprimearreglo(int* array, int size);
void swap(int* c, int* d);
int hoare(int a[], int p, int r);
void quicksort(int a[],int size, int inicio, int fin);

//Programa Principal
int main(int argc, char* argv[]) {
	int array[] = {4,5,9,2,1,4,5,6,7};
	quicksort(array, kSize, 0, kSize);
	imprimearreglo(array, kSize);
}

//Funciones 
void imprimearreglo(int* array, int size) {
	int i;
	for(i=0; i<size; ++i) {
		printf("%d     ", array[i]);
	}
	printf("\n");
}
void swap(int* c, int* d){
	double t;
	t=*c;
	*c=*d;
	*d=t;
}

/*Hoare-Partition (a, p, r)
 x ← A[p]
     i ← p − 1
     j ← r + 1
 while  TRUE
        repeat   j ←  j − 1
            until     A[j] > x
    repeat   i ←  i + 1
            until     A[i] < x
    if  i < j
              exchange  A[i] ↔ A[j]
    else  return   j+1 */

int hoare(int a[], int p, int r) {
	int x=a[p],i=p-1, j=r;
	while (1) {
		do j--;
		while (a[j]>x);
		do i++;
		while (a[i]<x);
		if (i<j) {
			swap(&a[i], &a[j]);
		} else {
			return j+1;
		}
	}
}
void quicksort(int a[],int size, int inicio, int fin) {
	int q;
	if (fin-inicio<2) return;
	q=hoare(a, inicio, fin);
	quicksort(a,kSize, inicio, q);
	quicksort(a,kSize, q, fin);
}