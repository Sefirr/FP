#include <iostream>
using namespace std;
#include <fstream>

int main()
{
   int i, num, ini = 1, fin;
   ifstream archivo;
   archivo.open("repetidos.txt");
   if (!archivo.is_open())
      cout << "Error de apertura del archivo!" << endl;
   else {
      cout << "Valor a localizar: ";
      cin >> num;
      bool encontrado = false, final = false;
      archivo >> i;
      while (!encontrado && !final) { // Localizar la primera ocurrencia
         if (i == 0)
            final = true;
         else if (i == num)
            encontrado = true;
         else {
            archivo >> i;
            ini++;
         }
      }
      if (encontrado) {
         fin = ini;
         archivo >> i;
         while (encontrado && !final) { // Recorrer todos los repetidos
            if (i == 0)
               final = true;
            else if (i > num)
               encontrado = false;
            else { // Sigue siendo num
               archivo >> i;
               fin++;
            }
         }
         cout << "Entre " << ini << " y " << fin << endl;
      }
      else
         cout << "No encontrado" << endl;
      archivo.close();
   }

   return 0;
}
