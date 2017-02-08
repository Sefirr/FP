/* ?10.   El �rea de un tri�ngulo se puede calcular mediante la ley del seno: si se conocen
dos lados del tri�ngulo, lado1 y lado2, y el �ngulo ? existente entre ellos. Dicha
ley establece que
�rea = �� x� lado1� x� lado2� x� sen ?
Implementa un programa que calcule el �rea de un tri�ngulo de esta manera. El
programa deber� solicitar al usuario los dos lados y el �ngulo que �stos forman
(en grados). Ten en cuenta que la funci�n sin() espera que el �ngulo se
proporcione en radianes. �ngulo en radianes = �ngulo en grados x ? / 180. */






#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double lado1, lado2, area, angulo, radianes;
	cout << "Primer lado del tri�ngulo :";
	cin >> lado1;
	cout << "Segundo lado del tri�ngulo :";
	cin >> lado2;
	cout << "�Cu�l es el �ngulo que forman los dos lados?:";
	cin >> angulo;
	radianes = angulo * 3.141592 / 180;
	area = lado1 * lado2 * sin(radianes);
	cout << "El �rea de un triangulo del primer lado de " << lado1 << " cm y del segundo lado de " << lado2 << " cm y cuyos lados forman un �ngulo de " << angulo << " grados es de " << area << " cm." << endl;
	
	return 0;
		}
