#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   int opcion;
   do {
      cout << "1 - Tablas de multiplicar" << endl;
      cout << "2 - Sumatorio" << endl;
      cout << "0 - Salir" << endl;
      do {
         cout << "Opción: ";
         cin >> opcion;
      } while ((opcion < 0) || (opcion > 2));
      if (opcion > 0)
         switch (opcion)
         {
            case (1):
               for (int i = 1; i <= 10; i++)
                  for (int j = 1; j <= 10; j++)
                  {
                     cout << setw(2) << i << " x "
                          << setw(2) << j << " = "
                          << setw(3) << i * j << endl;
                  }
               break;
            case (2):
               int num = 0;
               long long int total = 0;
               while (num <= 0) {
                  cout << "Hasta (positivo)? "; 
                  cin >> num;
               }
               for (int i = 1; i <= num; i++) 
                  total = total + i;
               cout << "La suma de los números entre 1 y "
                    << num << " es: " << total;
               break;
         }
      cout << endl;
   } while (opcion != 0);

   return 0;
}
