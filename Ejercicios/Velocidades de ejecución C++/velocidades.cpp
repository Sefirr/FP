#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>

const int Max = 100000;
typedef int tArray[Max]; // Lista de enteros

// Carga del array: asignación aleatoria entre 0 y N - 1
void cargar(tArray lista, int N);

// Mostrar una cabecera para los resultados...
void cabecera(int N);

// Rrealiza una órdenación, una búsqueda secuencial y una búsqueda binaria
// mostrando los ciclos que se realizan en cada caso...
void comparar(tArray lista, int N, int buscado);

// Ordenación por inserción con intercambios...
void ordenar(tArray lista, int N, long long int &ciclos);

// Búsqueda secuencial...
bool buscarBin(const tArray lista, int N, int buscado, int &pos, long long int &ciclos);

// Búsqueda binaria...
bool buscarSec(const tArray lista, int N, int buscado, int &pos, long long int &ciclos);

int main() {
   tArray lista;
   int N;
   char c;

   system("chcp 1252");
   srand(time(NULL));

   cout << endl << "Distintos tamaños y elemento no encontrado..." << endl;
   cout << "=============================================" << endl;
   for (int i = 10; i <= Max; i = i * 10) {
      cabecera(i);
      cargar(lista, i);
      comparar(lista, i, 120000);
   }

   N = 10000;
   cout << endl << "N = " << N << " y lista inicialmente ordenada..." << endl;
   cout <<         "==========================================" << endl;
   cabecera(N);
   for (int i = 0; i < N; i++)
      lista[i] = i;
   comparar(lista, N, rand() % 10000);

   cout << endl << "N = " << N << " y lista inicialmente ordenada al revés..." << endl;
   cout <<         "===================================================" << endl;
   cabecera(N);
   for (int i = 0; i < N; i++)
      lista[i] = N - i;
   comparar(lista, N, rand() % 10000);

   cout << endl << "N = " << N << " y elemento aleatorio..." << endl;
   cout << "=================================" << endl;
   cabecera(N);
   for (int i = 1; i < 20; i++) {
      cargar(lista, N);
      comparar(lista, N, rand() % 10000);
   }

   cout << "Pulsa Intro para terminar...";
   cin.get(c);

   return 0;
}

void cargar(tArray lista, int N) {
   for (int i = 0; i < N; i++)
      lista[i] = rand() % N;
}

void cabecera(int N) {
   long long int N2 = N;
   N2 = N2 * N;
   cout << endl << "N^2 = " << left << setw(14) << N2;
   cout << "N = " << setw(21) << N << "log N = " << log(double(N)) << endl;
   cout << "Ordenar             Búsqueda secuencial      Búsqueda binaria" << endl;
}

void comparar(tArray lista, int N, int buscado) {
   long long int ciclos;
   int pos;
   ordenar(lista, N, ciclos);
   cout << left << setw(20) << ciclos;
   buscarSec(lista, N, buscado, pos, ciclos);
   cout << left << setw(25) << ciclos;
   buscarBin(lista, N, buscado, pos, ciclos);
   cout << left << setw(25) << ciclos << endl;
}

void ordenar(tArray lista, int N, long long int &ciclos) {
   bool inter = true;
   int tmp, pos;
   ciclos = 0;
   // Desde el segundo elemento hasta el último...
   for (int i = 1; i < N; i++) {
      pos = i;
      ciclos++;
      // Mientras no al principio y anterior mayor...
      while ((pos > 0) && (lista[pos - 1] > lista[pos])) {
         // Intercambiar...
         ciclos++;
         tmp = lista[pos];
         lista[pos] = lista[pos - 1];
         lista[pos - 1] = tmp;
         pos--; // Posición anterior
      }
   }
}

bool buscarBin(const tArray lista, int N, int buscado, int &pos, long long int &ciclos) {
   int ini = 0, fin = N - 1, mitad;
   bool encontrado = false;
   ciclos = 0;
   while ((ini <= fin) && !encontrado) {
      ciclos++;
      mitad = (ini + fin) / 2; // División entera
      if (buscado == lista[mitad]) {
         encontrado = true;
      }
      else if (buscado < lista[mitad]) {
         fin = mitad - 1;
      }
      else {
         ini = mitad + 1;
      }
   }
   if (encontrado) {
      pos = mitad;
   }
   return encontrado;
}

bool buscarSec(const tArray lista, int N, int buscado, int &pos, long long int &ciclos) {
   bool encontrado = false;
   int i = 0;
   ciclos = 0;
   while ((i < N) && (lista[i] < buscado)) {
      ciclos++;
      i++;
   }
   if (i < N)
      if (lista[i] == buscado) { // Encontrado!
         encontrado = true;
         pos = i;
      }
   return encontrado;
}
