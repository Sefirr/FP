#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#include <cctype>

int main()
{
	const int IVA = 21, DESC = 15;
	double precio, total, porIVA, final, porDesc, TotalFacturado = 0, IvaGlobal = 0;
	int unidades, tantoDesc;
	char descuento;
	bool datoscliente = false, datosventa = false;
	string nombre, nif, direccion, producto;
	
	int opcion = -1;

	while(opcion != 0){
	cout << endl << "1 - Datos de cliente" << endl;
	cout << "2 - Datos de venta" << endl;
	cout << "3 - Factura" << endl;
	cout << "4 - Totales" << endl;
	cout << "5 - Reiniciar" << endl;
	cout << "0 - Salir";
	cout << endl << "Elige una opción: ";
	cin >> opcion;
	
		if(opcion == 1){
		cout << endl << "Nombre del cliente: ";
		cin.sync();
		getline(cin, nombre);
		cout << "NIF del cliente: ";
		cin.sync();
		getline(cin, nif);
		cout << "Dirección del cliente: ";
		cin.sync();
		getline(cin, direccion);
		
		datoscliente = true;
		
		}
		if(opcion == 2){
		
		cout << endl <<"Nombre del producto: ";
		cin.sync();
		getline(cin, producto);
		cout << "Precio del producto: ";
		cin >> precio;
		cout << "Unidades: ";
		cin >> unidades;
		cout << "Descuento (s/n)? ";
		cin >> descuento;
		
		datosventa = true;
		}
		
		if(opcion == 3){
		
		if (datoscliente == false){
		cout << endl <<"No has introducido datos de cliente." << endl;
		}
		else if (datosventa == false){
		cout << endl << "No has introducido datos de venta." << endl;
		}
		else  {
		cout << "3. Factura: " << endl;
		cout << endl << "Factura:" << endl;
		cout << setw(50) << right << nombre << endl;
		cout << setw(50) << right << direccion << endl;
		cout << setw(50) << right << nif << endl;
		cout << endl;
		cout << "Producto: " << producto << endl;
		cout << setw(40) << left << "Precio unitario";
		cout << setw(10) << right << fixed << setprecision(2) << precio << " €" << endl;
		cout << setw(40) << left << "Unidades";
		cout << setw(7) << right << unidades << endl;
		total = precio * unidades;
		cout << setw(40) << left << "Total";
		cout << setw(10) << right << fixed << setprecision(2) << total << " €" << endl;
        
		tantoDesc = 0;
		if(descuento == 's')
			tantoDesc = DESC;
		porDesc = total * tantoDesc / 100;
		cout << setw(40) << left << "Descuento";
		cout << setw(7) << right << tantoDesc << " %" << endl;
		cout << setw(50) << right << fixed << setprecision(2) << -porDesc << " €" << endl;
		total = total - porDesc;
		cout << setw(40) << left << "Total tras descuento";
		cout << setw(10) << right << fixed << setprecision(2) << total << " €" << endl;
        
		porIVA = total * IVA / 100;
		cout << setw(40) << left << "I.V.A.";
		cout << setw(7) << right << IVA << " %" << endl;
		cout << setw(50) << right << fixed << setprecision(2) << porIVA << " €" << endl;
		final = total + porIVA;
		cout << setw(40) << left << "Precio final";
		cout << setw(10) << right << fixed << setprecision(2) << final << " €" << endl;
		TotalFacturado = TotalFacturado + total;
		IvaGlobal = IvaGlobal + porIVA;
			}
		}
	
		
		if(opcion == 4) {

		cout << endl << setw(40) << left << "Total facturado: ";
		cout << setw(10) << right << fixed << setprecision(2) << TotalFacturado << " €" << endl;
		cout << setw(40) << left << "Total de I.V.A.: ";
		cout << setw(10) << right << fixed << setprecision(2) << IvaGlobal << " €" << endl;
		
		}
		
		if(opcion == 5){
		datosventa = datoscliente = false;
		TotalFacturado = IvaGlobal = 0;
			}
	
	
	}

	return 0;
}

	