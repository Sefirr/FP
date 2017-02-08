#include <iostream>
using namespace std;

int main() {
   const int N = 100;
   typedef int tArray[N];
   tArray nums; // Exactamente 100 enteros
   // Por ejemplo, los 100 primeros cuadrados:
   for (int i = 0; i < N; i++)
      nums[i] = i * i;
   double total = 0, media;
   for (int i = 0; i < N; i++)
      total = total + nums[i];
   media = total / N;
   cout << "Media de la lista de enteros: " << media << endl;
  
   return 0;
}
