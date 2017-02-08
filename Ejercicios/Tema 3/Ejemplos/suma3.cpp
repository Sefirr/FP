#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{ 
   double d, suma = 0;
   ifstream archivo; // Archivo de entrada (lectura)
   archivo.open("datos.txt");
   archivo >> d; // Obtener primero
   while (d != 0) { // Mientras queden datos, obtener siguiente
      suma = suma + d; // Procesar dato
      archivo >> d; // Obtener siguiente
   }
   cout << fixed << setprecision(3) << "Suma = " << suma << endl;
   archivo.close();

   return 0;
}
