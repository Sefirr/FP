/*5. Crea una estructura que represente una fecha y escribe un subprograma que,
dadas dos fechas, determine si la primera es mayor, menor o igual que la
segunda. */
#include <iostream>
using namespace std;

typedef struct {
	int dia;
	int mes;
	int anio;
} tFecha;

//Protótipos
bool operator>(tFecha fecha1, tFecha fecha2);
void introducirFecha(tFecha &fecha);

int main() {
	tFecha fecha1, fecha2;

	cout << "Introduce la primera fecha" << endl;
	introducirFecha(fecha1);
	cout << "Introduce la segunda fecha" << endl;
	introducirFecha(fecha2);


	cout << fecha1.dia << " de " << fecha1.mes << " del " << fecha1.anio << " ";
	if(fecha1 > fecha2)
		cout << "es mayor que ";
	else
		cout << "es menor o igual que ";

	cout << fecha2.dia << " de " << fecha2.mes << " del " << fecha2.anio << " ";

		
	return 0;
}

bool operator>(tFecha fecha1, tFecha fecha2) {
	bool resultado = false;
	if(fecha1.anio > fecha2.anio) {
		resultado = true;
		if(fecha1.mes > fecha2.mes) {
			if(fecha1.dia > fecha2.dia) {
				resultado = true;
			}
			else {
				resultado = false;
			}
		}
		else {
			resultado = false;
		}
		resultado = true;
	}
	else
		resultado = false;

	return resultado;
}

void introducirFecha(tFecha &fecha) {
	cout << "Día = ";
	cin >> fecha.dia;
	cout << "Mes = ";
	cin >> fecha.mes;
	cout << "Añi = ";
	cin >> fecha.anio;
}