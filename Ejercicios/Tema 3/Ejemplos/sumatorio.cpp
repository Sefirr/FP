#include <iostream>
using namespace std;

int main()
{
   int num, sumatorio = 0;
   cout << "N = ";
   cin >> num; // Número hasta el que llegar
   for (int i = 1; i <= num; i++)
      sumatorio = sumatorio + i; // Procesar (acumular) elemento
   cout << "Sumatorio de 1 a " << num 
        << " = " << sumatorio << endl;

   return 0;
}
