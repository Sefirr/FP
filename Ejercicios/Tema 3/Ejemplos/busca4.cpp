#include <iostream>
using namespace std;
#include <fstream>

int main()
{
   int i, num, cont = 1;
   ifstream archivo;
   
   archivo.open("repetidos.txt");
   cout << "Valor a localizar: ";
   cin >> num;
   
   archivo >> i;
   while ((i < num) && (i != 0)) {
      archivo >> i;
      cont++;
   }
   if (i == num) // Encontrada la primera ocurrencia
      while ((i == num) && (i != 0)) {
         cout << "Encontrado (pos.: " << cont << ")" << endl;
         archivo >> i;
         cont++;
      }
   archivo.close();

   return 0;
}
