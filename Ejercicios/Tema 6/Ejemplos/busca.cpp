#include <iostream>
#include <string>
using namespace std;

int main() {
   string cadena;
   char buscado;
   cout << "Introduce una cadena: ";
   getline(cin, cadena);
   cout << "Introduce el caracter a buscar: ";
   cin >> buscado;
   int pos = 0;
   bool encontrado = false;
   while ((pos < cadena.size()) && !encontrado) {
   // Mientras no se llegue al final de la cadena y no encontrado
      if (cadena.at(pos) == buscado)
         encontrado = true;
      else
         pos++;
   }
   if (encontrado)
      cout << buscado << " encontrado en la posición " << pos + 1;
   else
      cout << "No encontrado";
   cout << endl;

   return 0;
}
