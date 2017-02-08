/* Escribe un programa que lea un número entero positivo del teclado y lo muestre
invertido en la pantalla. Se entiende por invertir el dar la vuelta a los dígitos que
componen el número (su imagen especular). Esto es, el inverso de 3952 es 2593. */

#include <iostream>
using namespace std;
int main() {
   int valor;
   cout << "Introduce un número entero positivo: ";
   cin >> valor;
   if (valor > 0) {
      cout << "El número invertido es: ";
      while (valor != 0) {
         cout << valor % 10;
         valor = valor / 10;
      }
   }
   else
      cout << "El número no es positivo";
   cout << endl;
  
   return 0;
}
