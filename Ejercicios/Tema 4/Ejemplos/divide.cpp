#include <iostream>
using namespace std;

void divide(int op1, int op2, int &div, int &rem); // Prototipo

int main() {
  int cociente, resto;
  for (int j = 1; j <= 4; j++)
    for (int i = 1; i <= 4; i++) {
      divide(i, j, cociente, resto);
      cout << i << " entre " << j << " da un cociente de " 
           << cociente << " y un resto de " << resto << endl;
    }
  
  return 0;
}

void divide(int op1, int op2, int &div, int &rem)
// Divide op1 entre op2 y devuelve el cociente y el resto.
{
  div = op1 / op2;
  rem = op1 % op2;
}
