#include <iostream>
using namespace std;

int main()
{
   int mes, anio, dias;
   cout << "N�mero de mes: "; 
   cin >> mes;
   cout << "A�o: "; 
   cin >> anio;
   if (mes == 2) 
      if ((anio % 4) == 0) // Divisible por 4
         if (((anio % 100) == 0) && ((anio % 400) != 0))
            // Pero �ltimo de siglo y no m�ltiplo de 400
            dias = 28;
         else
            dias = 29; // A�o bisiesto
      else
         dias = 28;
   else 
      if ((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7)
          || (mes == 8) || (mes == 10) || (mes == 12))
         dias = 31;
      else
         dias = 30;
         
   cout << "D�as de ese mes: " << dias;
   
   return 0;
}
