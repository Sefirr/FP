#include <iostream>
using namespace std;

int main()
{
   int op1 = 13, op2 = 4, resultado;
   int opcion;
   char operador;
   cout << "1 - Sumar" << endl;
   cout << "2 - Restar" << endl;
   cout << "Opcion: ";
   cin >> opcion;
   if (opcion == 1) {
      operador = '+';
      resultado = op1 + op2;
   }
   else {
      operador = '-';
      resultado = op1 - op2;
   }
   cout << op1 << operador << op2 << " = " << resultado << endl;

   return 0;
}
