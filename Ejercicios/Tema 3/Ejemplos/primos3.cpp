#include <iostream>
using namespace std;

int main()
{
   int num;
   cout << "Entero en el que parar (>1): ";
   cin >> num;
   if (num > 1) {
      int candidato = 2;
      if (candidato < num) {
         cout << candidato << " "; // 2 es primo
         candidato++; // Empieza con candidato = 3 (primo)
         while (candidato < num) {
            cout << candidato << " ";
            bool esPrimo;
            do {
               candidato = candidato + 2;
               esPrimo = true;
               int i = 3;
               while ((i <= candidato / 2) && esPrimo) {
                  if (candidato % i == 0)
                     esPrimo = false;
                  i = i + 2;
               }
            } while (!esPrimo);
         }
      }
   }

  return 0;
}
