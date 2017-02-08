#include <iostream>
using namespace std;

int main()
{
	int num, factor = 0, resultado;

	cout << "Introduce un número: ";
	cin >> num;
	
	while( num != 0 ){
	if( num > 0 && num < 100 && factor < 10){
	++factor;
	resultado = factor * num;
	
	cout << factor << " x " << num << " = " << resultado << endl;
	}
}
		
	return 0;
}