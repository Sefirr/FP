#include <iostream>
using namespace std;
#include <fstream>

int main()
{
   int i, num, cont = 0;
   bool encontrado = false;
   ifstream archivo;
   archivo.open("enteros.txt");
   cout << "Valor a localizar: ";
   cin >> num;
   archivo >> i;
   while ((i != 0) && !encontrado) {
      cont++;
      if (i == num)
         encontrado = true;
      archivo >> i;
   }
   if (encontrado)
      cout << "Encontrado (pos.: " << cont << ")";
   else
      cout << "No encontrado";
   cout << endl;
   archivo.close();

   return 0;
}
