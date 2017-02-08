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

   ofstream archivo;
   double dato;

   for (int i = 0; i < N; i++)
      miLista.elementos[i] = i;
   miLista.contador = N;
   archivo.open("backup.txt");
   if (!archivo.is_open())
      cout << "ERROR: No se ha podido crear el archivo!" << endl;
   else {
      // Ahora creamos la copia de seguridad...
      for (int i = 0; i < miLista.contador; i++) // Recorremos array
         archivo << miLista.elementos[i] << endl;
      archivo << -1 << endl; // Centinela final
      archivo.close();
   }
  
   return 0;
}
