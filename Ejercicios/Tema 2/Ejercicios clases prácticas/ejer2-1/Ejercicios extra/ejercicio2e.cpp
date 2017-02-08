#include <iostream>
#include <string>
using namespace std;
#include <cmath>

int main()
{	
	string nombre, apellido, dni;
	char letra_nif;
	int edad, ans, plazo;
	double capital, cuota, ratio;
		
	cout << "Nombre: ";
	cin >> nombre;
	cout << "Apellido: ";
	cin >> apellido;
	cout << "Edad: ";
	cin >> edad;
	cout << "DNI (8 dígitos): ";
	cin >> dni;
	cout << "Letra del NIF: ";
	cin >> letra_nif;
	cout << "Capital a prestar: ";
	cin >> capital;
	cout << "Años: ";
	cin >> ans;
	plazo = ans * 12;
	
	cout << endl << "Cliente: " << nombre << "\t" << apellido << " (" << edad << " años)" << endl;
	cout << "N.I.F.: " << dni << "-" << letra_nif << endl << endl;
	
	ratio = 2.25 / 12;
	cuota = (capital * ratio) / (100 * (1 - pow(1 + (ratio / 100), -plazo))); // Cuota anual del 2.25%
	cout << "Al 2.25% la cuota mensual sería de " << cuota << endl;
	ratio = 2.5 / 12;
	cuota = (capital * ratio) / (100 * (1 - pow(1 + (ratio / 100), -plazo))); // Cuota anual del 2.5%
	cout << "Al 2.5% la cuota mensual sería de " << cuota << endl;
	ratio = 2.75 / 12;
	cuota = (capital * ratio) / (100 * (1 - pow(1 + (ratio / 100), -plazo))); // Cuota anual del 2.75%	
	cout << "Al 2.75% la cuota mensual sería de " << cuota;

	return 0;
}
