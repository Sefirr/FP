#include <iostream>
using namespace std;

// Prototipos
long long int factorial(int n);
int sumatorio(int n);

long long int factorial(int n)
{
  long long int fact;
  if (n < 0) fact = 0;
  else
    for (int i = 1; i <= n; i++)
      fact *= i;
  return fact;
}

int sumatorio(int n)
{
  int sum;
  if (n < 0) sum = 0;
  else
    for (int i = 1; i <= n; i++)
      sum += i;
  return sum;
}

int main() {
  int num;
  cout << "Num: "; cin >> num;
  cout << "El factorial de " << num 
       << " es " << factorial(num)
       << " y el sumatorio de 1 a " 
       << num << " es " << sumatorio(num)
       << endl;

  return 0;
}
