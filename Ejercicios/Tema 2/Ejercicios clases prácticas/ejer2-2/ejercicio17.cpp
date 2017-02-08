#include <iostream>
using namespace std;

int main()
{
	double num;
	char medida;
		
	cout <<"Unidades: pulgadas (p), millas (m), ºF (f), galones (g), onzas (o), libras (l)" << endl << "Introduce una medida (cantidad seguida de letra de unidad; 0 para terminar): ";
	cin >> num >> medida;

	const double PulgadasaCentimetros = num / 2.54;
	const double MillasaMetros = num * 100;
	const double FarenheitaCelsius = (num - 32) / 1.8;
	const double GalonesaLitros = num * 3.785;
	const double OnzasaGramos = num * 28.35;
	const double LibrasaKilos = num * 0.454;			

while(num != 0){
	
	if(num > 0) {
		if(medida == 'p') {
		num = PulgadasaCentimetros;
		cout << "Equivalente a " << num << " cm " << endl;	
		}
		if (medida == 'm') {
		num = MillasaMetros;
		cout << "Equivalente a " << num << " m " << endl;
		}
		if(medida == 'f') {
		num = FarenheitaCelsius;
		cout << "Equivalente a " << num << " C " << endl;
		}
		if(medida == 'g') {
		num = GalonesaLitros;
		cout << "Equivalente a " << num << " l " << endl;	
		}
		if(medida == 'o') {
		num = OnzasaGramos;
		cout << "Equivalente a " << num << " gr " << endl;
		}
		if(medida == 'l') {
		num = LibrasaKilos;
		cout << "Equivalente a " << num << " kg " << endl;
		}
	} 
	cout << "Introduce un número (0 para terminar): ";
	cin >> num >> medida;	
	}
		
		
	return 0;
}