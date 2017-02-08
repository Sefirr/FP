#include <iostream>
using namespace std;

int main()
{
   double d, suma = 0, media = 0;
   int cont = 0;
   cout << "Introduce un número (0 para terminar): ";
   cin >> d;
   while(d != 0) {
      suma = suma + d;
      cont++;
      cout << "Introduce un número (0 para terminar): ";
      cin >> d;
   }
   if (cont > 0)
      media = suma / cont;
   cout << "Suma = " << suma << endl;
   cout << "Media = " << media << endl;

   return 0;
}
