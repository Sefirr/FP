#include <iostream>
using namespace std;

int main()
{
   char buscado, c;
   cout << "Car�cter a buscar: ";
   cin >> buscado;
   cout << "Cadena: ";
   cin >> c;
   int cont = 0;
   while (c != '*') {
      if (c == buscado)
         cont++;
      cin >> c;
   }
   cout << buscado << " aparece " << cont << " veces.";

   return 0;
}
