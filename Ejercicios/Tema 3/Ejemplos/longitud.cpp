#include <iostream>
using namespace std;

int main()
{
   char c;
   int longitud = 0;
   cout << "Cadena terminada en punto: ";
   cin >> c;             // Obtener primer car�cter
   while (c != '.') {    // Mientras no sea el centinela
      longitud++;        // Procesar
      cin >> c;          // Obtener siguiente car�cter
   }
   cout << "Longitud = " << longitud << endl;

   return 0;
}
