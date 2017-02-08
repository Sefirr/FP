/* Escribe un programa que invierta cada número entero positivo 
que se introduzca por teclado. El programa actuará de forma cíclica, 
finalizando la ejecución cuando se introduzca un número negativo o el cero. */

#include <iostream>
using namespace std;
int main() {
   int valor;
   cout << "Introduce un número entero positivo: ";
   cin >> valor;
   do 
   {
      cout << "El número invertido es: ";
      
	  while (valor != 0) {
         cout << valor % 10;
         valor = valor / 10;
      }
	  
	cout << endl;
	
   } while(valor > 0);
  
   return 0;
}
