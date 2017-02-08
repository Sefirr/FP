#include <iostream>
using namespace std;

int main()
{
   double d, num;
   ifstream archivo; // Archivo de entrada
   archivo.open("datos2.txt");
   cout << "Encontrar primero mayor que: ";
   cin >> num;
   bool encontrado = false;
   do {
      archivo >> d; // Obtener el siguiente elemento de la secuencia
      if (d > num)
         encontrado = true;
   } while ((d != -1) && !encontrado);
   if (encontrado)
      cout << "Encontrado";
   else
      cout << "No encontrado";
   archivo.close();

   return 0;
}
