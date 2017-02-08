// Tema 2 - Ejercicio 21

#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#include <cctype> // Para convertir a mayúscula

int main() {
   const int IVA = 21, DESC = 15;
   double precio, total, porIVA, final, porDesc;
   char descuento;
   int unidades, tantoDesc;
   string nombre, nif, direccion, producto;
   
   cout << "Precio del producto: ";
   cin >> precio;
   cout << "Unidades: ";
   cin >> unidades;
   cout << "Descuento (s/n)? ";
   cin >> descuento;
   descuento = toupper(descuento);
   cout << "Nombre del cliente: ";
   cin.sync();
   getline(cin, nombre);
   cout << "NIF del cliente: ";
   cin.sync();
   getline(cin, nif);
   cout << "Dirección del cliente: ";
   cin.sync();
   getline(cin, direccion);
   cout << "Nombre del producto: ";
   cin.sync();
   getline(cin, producto);
   
   cout << endl << "Factura:" << endl;
   cout << setw(50) << right << nombre << endl;
   cout << setw(50) << right << direccion << endl;
   cout << setw(50) << right << nif << endl;
   cout << endl;
   cout << "Producto: " << producto << endl;
   cout << setw(40) << left << "Precio unitario";
   cout << setw(10) << right << fixed 
        << setprecision(2) << precio << " €" << endl;
   cout << setw(40) << left << "Unidades";
   cout << setw(7) << right << unidades << endl;
   total = precio * unidades;
   cout << setw(40) << left << "Total";
   cout << setw(10) << right << fixed 
        << setprecision(2) << total << " €" << endl;
        
   tantoDesc = 0;
   if (descuento == 'S')
      tantoDesc = DESC;
   porDesc = total * tantoDesc / 100;
   cout << setw(40) << left << "Descuento";
   cout << setw(7) << right << tantoDesc << " %" << endl;
   cout << setw(50) << right << fixed 
        << setprecision(2) << -porDesc << " €" << endl;
   total = total - porDesc;
   cout << setw(40) << left << "Total tras descuento";
   cout << setw(10) << right << fixed 
        << setprecision(2) << total << " €" << endl;
        
   porIVA = total * IVA / 100;
   cout << setw(40) << left << "I.V.A.";
   cout << setw(7) << right << IVA << " %" << endl;
   cout << setw(50) << right << fixed 
        << setprecision(2) << porIVA << endl;
   final = total + porIVA;
   cout << setw(40) << left << "Precio final";
   cout << setw(10) << right << fixed 
        << setprecision(2) << final << " €" << endl;
        
   return 0;
}
