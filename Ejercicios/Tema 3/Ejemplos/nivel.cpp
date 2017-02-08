#include <iostream>
using namespace std;

int main() {
   int num;
   cout << "Introduce nivel: ";
   cin >> num;
   if (num == 5)
      cout << "Muy alto" << endl;
   else if (num == 4)
      cout << "Alto" << endl;
   else if (num == 3)
      cout << "Medio" << endl;
   else if (num == 2)
      cout << "Bajo" << endl;
   else if (num == 1)
      cout << "Muy bajo" << endl;
   else
      cout << "Valor no válido" << endl;
  
   return 0;
}
