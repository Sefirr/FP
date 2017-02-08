/* Escribe un programa que invierta cada n�mero entero positivo 
que se introduzca por teclado. El programa actuar� de forma c�clica, 
finalizando la ejecuci�n cuando se introduzca un n�mero negativo o el cero. */

#include <iostream>
using namespace std;
int main() {
   int valor;
   cout << "Introduce un n�mero entero positivo: ";
   cin >> valor;
   do 
   {
      cout << "El n�mero invertido es: ";
      
	  while (valor != 0) {
         cout << valor % 10;
         valor = valor / 10;
      }
	  
	cout << endl;
	
   } while(valor > 0);
  
   return 0;
}
