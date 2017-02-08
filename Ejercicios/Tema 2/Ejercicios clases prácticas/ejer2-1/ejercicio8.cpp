#include <iostream>
using namespace std;

int main()
{
	double sueldobase, complemento_c, sueldobruto, irpf, irpf_retencion, sueldoneto;
	int complemento_d, hijos, extrahoras, mayoresdep;
	cout << "Sueldo base : ";
	cin >> sueldobase;
	cout << "Complemento de destino : ";
	cin >> complemento_d;
	cout << "Complemento de cargo academico : ";
	cin >> complemento_c;
	cout << "Horas extra : ";
	cin >> extrahoras;
	cout << "Hijos : ";
	cin >> hijos;
	cout << "Mayores dependientes : ";
	cin >> mayoresdep ;
	cout << "Cálculo de nomina.- ";
	sueldobruto = sueldobase + complemento_c + complemento_d + (extrahoras * 23);
	if(hijos != 0 && mayoresdep != 0)
	irpf = 0.24;
	if(hijos > 0)
	irpf = irpf + 0.02;
	if(mayoresdep > 0)
	irpf = irpf - 0.01;
	
	irpf_retencion = sueldobase* irpf;
	sueldoneto = sueldobase -  irpf_retencion;
	cout << " Porcentaje de IRPF : " << irpf << endl;
	cout << " Retención de IRPF : " << irpf_retencion << endl;
	cout << " Sueldo neto : " << sueldoneto;

	return 0;
		}
