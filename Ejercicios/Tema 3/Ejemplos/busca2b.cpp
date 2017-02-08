#include <iostream>
using namespace std;

int main()
{
   double d, num;
   cout << "Encontrar primero mayor que: ";
   cin >> num;
   bool encontrado = false;
   do {
      cout << "Siguiente (-1 para terminar): ";
      cin >> d;
      if (d > num)
         encontrado = true;
   } while ((d != -1) && !encontrado);
   if (encontrado)
      cout << "Encontrado";
   else
      cout << "No encontrado";

   return 0;
}
