#include <iostream>
#include <string>
using namespace std;

int main() {
   string cadena, inversa;
   cout << "Introduce una cadena: ";
   getline(cin, cadena);
   int pos = 0;
   while (pos < cadena.size()) {
   // Mientras no se llegue al final de la cadena
      char car = cadena.at(pos);
      inversa = car + inversa;
	   pos++;
   }
   cout << "Cadena invertida: " << inversa << endl;

   return 0;
}
