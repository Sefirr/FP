#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a = 10;
	char b = 'x';
	double c = 3.33333;
	cout << a << c << b << endl; //103.33333x
	cout << setw(5) << a << setw(10) << setprecision(2) << c << b << endl; //10	3.3x
	cout << setw(5) << setprecision(2) << c << setw(10) << b << setw(10) << b << endl; // 3.3		x		x
	return 0;
}