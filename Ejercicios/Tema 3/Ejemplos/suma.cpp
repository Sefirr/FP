#include <iostream>
using namespace std;

int main()
{
   int num;
   long long int total = 0;
   cout << "N�mero final: "; 
   cin >> num;
   if (num <= 0) 
      cout << "�El n�mero debe ser positivo!" << endl;
   else {
      for(int i = 1; i <= num; i++) 
         total = total + i;
      cout << "La suma de los n�meros entre 1 y " << num << " es: " << total;
   }

   return 0;
}
