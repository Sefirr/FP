#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   double d1, d2;
   ifstream sec1, sec2;
   bool iguales;
   bool final;
   sec1.open("secuencia1.txt");
   sec2.open("secuencia2.txt");
   do {
      sec1 >> d1;
      sec2 >> d2;
      // En los archivos al menos estarán los centinelas (0)
      iguales = (d1 == d2);
      final = ((d1 == 0) && (d2 == 0));
   } while (iguales && !final);
   cout << "Las secuencias " << (iguales ? "SI" : "NO") 
        << " son iguales" << endl;
   sec1.close();
   sec2.close();

   return 0;
}
