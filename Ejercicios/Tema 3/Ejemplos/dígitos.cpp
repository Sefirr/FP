#include <iostream>
using namespace std;

int main()
{
   int num, digitos = 0;
   cout << "Introduce un n�mero entero: ";
   cin >> num;
   do {
      digitos++;
      num = num / 10;
   } while(num != 0);
   cout << "D�gitos: " << digitos;

   return 0;
}
