#include <iostream>
using namespace std;
#include <fstream>

int main()
{
   double d;
   ofstream archivo;
   archivo.open("output2.txt"); // Apertura
   archivo << "X = " << 123.45 << endl;
   archivo << "Y = " << 6.1145 << endl;
   archivo << "Z = " << 15637 << endl;
   archivo.close(); // Cierre del archivo

   return 0;
}
