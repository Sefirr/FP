#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{ 
   double d, suma = 0;
   ifstream archivo; // Archivo de entrada (lectura)
   archivo.open("datos.txt");
   do {
      archivo >> d; // Obtener siguiente
      if (d != 0) // Si no es el centinela...
         suma = suma + d; // Procesar dato
   } while (d != 0); // Mientras no sea el centinela
   cout << fixed << setprecision(3) << "Suma = " << suma << endl;
   archivo.close();

   return 0;
}
