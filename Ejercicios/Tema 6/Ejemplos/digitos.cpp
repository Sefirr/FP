#include <iostream>
using namespace std;
#include <cstdlib> // Necesaria para usar rand()

int digitos(int);

int main() {
   const int N = 100;
   typedef int tNum[N]; // Exactamente 100 números
   tNum num;
   const int D = 6;
   typedef int tDig[D];
   tDig dig = { 0 };
   // Posición i --> cantidad de números de i+1 dígitos
  
   for (int i = 0; i < N; i++)
      num[i] = rand();
   
   int dato, numDig;
   for (int i = 0; i < N; i++) {
      dato = num[i];
      numDig = digitos(dato);
      if (numDig <= D)
         dig[numDig - 1]++;
   }
  
   for (int i = 0; i < D; i++)
      cout << "De " << i + 1 << " dig. = " << dig[i] << endl;
   
   return 0;
}

int digitos(int dato) {
   int n_digitos = 1;
   while (dato >= 10) {
      dato = dato / 10;
      n_digitos++;
   }
   return n_digitos;
}
