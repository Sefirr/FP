#include <iostream>
using namespace std;

int main()
{
	int horas, minutos, segundos1, segundos2, resto1, resto2;
	cout << " Segundos = ";
	cin >> segundos1;
	horas = segundos1 / 3600;
	resto1 = segundos1 - horas *3600;
	minutos = resto1 / 60;
	resto2 = resto1 - minutos*60;
	segundos2 = resto2;
	cout << segundos1 << " segundos son " << horas << " horas " << minutos << " minutos " << segundos2 << " segundos." << endl;
	return 0;
}
