#include <iostream>
using namespace std;
#include <fstream>

int main()
{
   double temp, total = 0, media;
   int cont = 0;
   ifstream archivo;
   archivo.open("temp.txt");
   archivo >> temp;
   if (temp == 0)
      cout << "Serie vacia!";
   else {
      while (temp != 0) {
         total = total + temp;
         cont++;
         archivo >> temp;
      }
      media = total / cont;
      cout << "Media de temperatura = " << media;
   }
   archivo.close();

   return 0;
}
