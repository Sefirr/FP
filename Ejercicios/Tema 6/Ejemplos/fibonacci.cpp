#include <iostream>
using namespace std;

int main() {
   const int N = 50;
   typedef long long int tFibonacci[N]; // Exactamente 50 números
   tFibonacci fib;
   fib[0] = 1;
   fib[1] = 1;
   for (int i = 2; i < N; i++)
      fib[i] = fib[i - 1] + fib[i - 2];
   for (int i = 0; i < N; i++)
      cout << fib[i] << "   ";
   
   return 0;
}
