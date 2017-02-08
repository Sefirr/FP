/* Debido a una pertinaz sequía se decidió poner en práctica un sistema de cobro
de agua que penalice el consumo excesivo tal como indica la tabla siguiente:
Consumo (m3) €/ m3
Primeros 100 0,15
De 100 a 500 0,20
De 500 a 1000 0,35
Más de 1000 0,80
Escribe un programa que lea del teclado los metros cúbicos consumidos y
muestre en la pantalla el coste de agua total. Ten en cuenta que en la tabla se
indica lo que hay que cobrar por los m3 que se encuentran en el intervalo. Así, si
hemos consumido 750 m3 deberíamos pagar: 100 * 0,15 + 400 * 0,20 + 250 *
0,35 = 182,50 €. Usa constantes. */

#include <iostream>
using namespace std;

int main()
{
	int metros;
	double coste_agua = 0;

	const double Coste100 = 0.15;
	const double Coste100_500 = 0.20;
	const double Coste500_1000 = 0.35;
	const double CosteMas = 0.80;

	cout << endl << "¿Cuántos metros cúbicos ha consumido? ";
	cin >> metros;

	if(metros < 0)
		cout  << "Ha de ser positiva";
	if(metros >= 100)
		coste_agua = coste_agua + metros * 0.15;
	if(metros > 100 && metros <= 500)
		coste_agua = coste_agua + metros * 0.20;
	if(metros > 500 && metros <= 1000)
		coste_agua = coste_agua + metros * 0.35;
	if(metros > 1000)
		coste_agua = coste_agua + metros * 0.8;

	cout << "Coste del agua total: " << coste_agua;

	return 0;
}