#include <iostream>
using namespace std;

int main()
{
	double operando1;
	double operando2;
	char operador;
	
	cout << "Operando Operador Operando (0 para terminar): ";
	cin >> operando1 >> operador >> operando2;
	while(operando1 != 0 && operando2 !=0){
	if(operador == '+'){
	cout << operando1 << " " << operador << " " << operando2 << " = " << operando1 + operando2 << endl;	
	}
	if(operador == '-')	{
	cout << operando1 << " " << operador << " " << operando2 << " = " << operando1 - operando2 << endl;	
	}
	if(operador == '/')	{
	cout << operando1 << " " << operador << " " << operando2 << " = " << operando1 / operando2 << endl;	
	}
	if(operador == '*')	{
	cout << operando1 << " " << operador << " " << operando2 << " = " << operando1 * operando2 << endl;	
	}
	cout << "Operando Operador Operando (0 para terminar): ";
	cin >> operando1 >> operador >> operando2;
}		
	return 0;
}