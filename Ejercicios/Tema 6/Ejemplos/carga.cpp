#include <iostream>
using namespace std;
#include <fstream>

int main() {
   const int N = 100;
   typedef double tArray[N];
   typedef struct {
      tArray elementos;
      int contador;
   } tLista;
   tLista miLista;

   ifstream archivo;
   double dato;

   miLista.contador = 0;
   archivo.open("datos.txt"); // Centinela al final: -1
   if (!archivo.is_open())
      cout << "ERROR: No existe el archivo!" << endl;
   else {
      bool overflow = false;
      archivo >> dato;
      while ((dato >= 0) && !overflow) {
         if (miLista.contador == N)
            overflow = true; // Demasiados!
         else {
            miLista.elementos[miLista.contador] = dato;
            miLista.contador++;
            archivo >> dato;
         }
      }
      if (overflow)
         cout << "Había más datos en el archivo de los que caben!" << endl;
      // En cualquier caso, los mostramos...
      for (int i = 0; i < miLista.contador; i++) {
         dato = miLista.elementos[i];
         cout << dato << "  ";
      }
      cout << endl;
      archivo.close();
   }

   return 0;
}
