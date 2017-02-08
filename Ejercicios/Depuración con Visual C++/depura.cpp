//
//
// Nombre y apellidos:
//
//

#include <iostream>
using namespace std;

const int N = 10;

typedef double tTabla[N];
typedef struct {
   tTabla elem;
   int cont;
} tLista;

bool insertar(tLista lista, double dato);
void mostrar(tLista lista);

int main() {
   tLista lista;
   double dato;
   do {
      cout << "Dato a insertar (positivo, 0 para terminar): ";
      cin >> dato;
      insertar(lista, dato);
   } while (dato > 0);
   mostrar(lista);

   
   return 0;
}

bool insertar(tLista lista, double dato) {
   bool ok = true;
   if (lista.cont > N) ok = false;
   else {
      lista.elem[lista.cont] = dato;
      lista.cont++;
   }
   return ok;
}

void mostrar(tLista lista) {
   for (int i = 0; i < lista.cont; i++)
      cout << lista.elem[i] << "  ";
   cout << endl;
}
