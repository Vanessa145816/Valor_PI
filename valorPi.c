/***************************************************
  Fórmula para calcula la aproximación de PI. 
  mediante el metodo de Algoritmo John Wallis
  PI= 2(2/1 x 2/3 x 4/3 x 4/5....)         
  ***************************************************/
#include <stdio.h>
int main (int argc, char** argv[]){
      float PI = 2, n = 1, o = 2;
      int i;
 
      for (i = 0; i < 100; i++) {
          
          PI *= (o/n);
 
          if (i % 2 == 0)  // si el resto es 0 K suma y asigna. 
             n += 2;
          else
             o += 2;
      }
 
      printf("El valor aproximado de Pi es: %1.52lf", PI);
 
      return 0;
}
 