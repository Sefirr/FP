#include <iostream>
using namespace std;

int main()
{
   int num;
   cout << "Introduce un n�mero entre 1 y 10: ";
   cin >> num;
   if ((num >= 1) && (num <= 10))
      cout << "N�mero dentro del intervalo de valores v�lidos";
   else
      cout << "N�mero no v�lido";

   return 0;
}
