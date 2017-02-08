#include <iostream>
using namespace std;
#include <fstream>

int main()
{
   double d;
   ifstream archivo;
   archivo.open("input2.txt"); // Apertura
   if (!archivo.is_open())
      cout << "¡No se pudo abrir el archivo!" << endl;
   else {
      archivo >> d;
      cout << d << endl;
      archivo >> d;
      cout << d << endl;
      archivo.close(); // Cierre del archivo
   }
   return 0;
}
