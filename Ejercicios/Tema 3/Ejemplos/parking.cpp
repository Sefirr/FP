#include <iostream>
using namespace std;
#include <fstream>

int main()
{
   int coches;
   char c;
   bool terminar = false;
   
   ifstream archivo;
   archivo.open("parking.txt");
   
   while (!terminar) {
      archivo >> c;
      if (c == '.') // . como primer carácter? (centinela)
         terminar = true;
      else {
         coches = 0;
         while (c != '.') {
            if (c == 'E')
               coches++;
            else if (c == 'S')
               coches--;
            archivo >> c;
         }
         if (coches >= 0)
            cout << "Quedan " << coches << " coches.";
         else
            cout << "Error: Mas salidas que entradas!";
         cout << endl;
      }
   }
   archivo.close();

   return 0;
}
