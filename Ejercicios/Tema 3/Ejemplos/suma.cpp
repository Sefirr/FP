#include <iostream>
using namespace std;

int main()
{
   int num;
   long long int total = 0;
   cout << "Número final: "; 
   cin >> num;
   if (num <= 0) 
      cout << "¡El número debe ser positivo!" << endl;
   else {
      for(int i = 1; i <= num; i++) 
         total = total + i;
      cout << "La suma de los números entre 1 y " << num << " es: " << total;
   }

   return 0;
}
