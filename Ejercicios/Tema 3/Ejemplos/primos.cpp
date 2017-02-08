#include <iostream>
using namespace std;

int main()
{
   int num;
   cout << "Entero en el que parar (>1): ";
   cin >> num;
   if (num > 1) {
      int candidato = 2; // El 1 no se considera un número candidato
      while (candidato < num) {
         cout << candidato << " "; // Mostrar el número candidato
         bool esPrimo;
         do { // Obtener el siguiente número candidato
            candidato++;
            esPrimo = true;
            for (int i = 2; i <= candidato - 1; i++)
               if (candidato % i == 0)
                  esPrimo = false; // Es divisible por i
         } while (!esPrimo);
      }
   }

   return 0;
}
