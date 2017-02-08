/* Escribe un programa que lea un n�mero entero positivo del teclado y lo muestre
invertido en la pantalla. Se entiende por invertir el dar la vuelta a los d�gitos que
componen el n�mero (su imagen especular). Esto es, el inverso de 3952 es 2593. */

#include <iostream>
using namespace std;
int main() {
   int valor;
   cout << "Introduce un n�mero entero positivo: ";
   cin >> valor;
   if (valor > 0) {
      cout << "El n�mero invertido es: ";
      while (valor != 0) {
         cout << valor % 10;
         valor = valor / 10;
      }
   }
   else
      cout << "El n�mero no es positivo";
   cout << endl;
  
   return 0;
}
