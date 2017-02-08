#include <iostream>
using namespace std;
#include <fstream>

int main()
{
   double total1 = 0, total2 = 0, d1, d2;
   ifstream archivo;
   archivo.open("ventas.txt");
   archivo >> d1 >> d2;
   while (!((d1 == 0) && (d2 == 0))) {
      total1 += d1;
      total2 += d2;
      archivo >> d1 >> d2;
   }
   archivo.close();
   cout << "Total P1 = " << total1 << endl;
   cout << "Total P2 = " << total2 << endl;

   return 0;
}
