#include <iostream>
using namespace std;

int main()
{
   int num;
   cout << "Entero en el que parar (>1): ";
   cin >> num;
   if (num > 1) {
      int candidato = 2; // El 1 no se considera un n�mero candidato
      while (candidato < num) {
         cout << candidato << " "; // Mostrar el n�mero candidato
         bool esPrimo;
         do { // Obtener el siguiente n�mero candidato
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
