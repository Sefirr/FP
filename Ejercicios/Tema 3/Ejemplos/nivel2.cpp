#include <iostream>
using namespace std;

int main() {
   int num;
   cout << "Introduce nivel: ";
   cin >> num;
   switch (num) {
      case 5:
         cout << "Muy alto";
         break;
      case 4:
         cout << "Alto";
         break;
      case 3:
         cout << "Medio";
         break;
      case 2:
         cout << "Bajo";
         break;
      case 1:
         cout << "Muy bajo";
         break;
      default:
         cout << "Valor no válido";
   }
  
   return 0;
}
