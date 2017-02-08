#include <iostream>
using namespace std;
#include <fstream>

const int N = 100;
typedef double tArray[N];
typedef struct {
   tArray elementos;
   int contador;
} tLista;

bool cargar(tLista &lista);

int main() {
   tLista lista;
   if (!cargar(lista))
      cout << "Error de archivo: inexistente o con demasiados datos"
           << endl;
   else {
      double umbral;
      cout << "Valor umbral: "; cin >> umbral;
      bool encontrado = false;
      int pos = 0;
      while ((pos < lista.contador) && !encontrado)
         if (lista.elementos[pos] > umbral)
            encontrado = true;
         else
            pos++;
      if (encontrado)
         cout << "Valor en pos. " << pos + 1 << " (" 
              << lista.elementos[pos] << ")" << endl;
      else cout << "No encontrado!" << endl;
   }

   return 0;
}

bool cargar(tLista &lista) {
   ifstream archivo;
   double dato;
   bool abierto = true;
   bool overflow = false;
   lista.contador = 0;
   archivo.open("datos.txt");
   if (!archivo.is_open())
      abierto = false;
   else {
      archivo >> dato;
      while ((dato >= 0) && !overflow) {
         if (lista.contador == N)
            overflow = true; // Demasiados!
         else {
            lista.elementos[lista.contador] = dato;
            lista.contador++;
            archivo >> dato;
         }
      }
   }
   return (abierto && !overflow);
}
