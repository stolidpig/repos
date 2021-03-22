#include "../../std_lib_facilities.h"

double ctok(double c)
{
	if (c < -273.15)
		error("Error");
	double k = c + 273.15;
	return k;
}

double ktoc(double k)
{
	if (k < 0)
		error("Error");
	double c = k - 273.15;
	return c;
}

double ctof (double c)
{

	double f = (c * 1.8)+ 32;
	return f;
}

double ftoc(double f)
{

	double c = (f - 32) / 1.8;
	return c;
}

int main()
{
	double temp = 0;
	cin >> temp;
	double k = ctok(temp);
	cout << k << " - K\n";
	double c = ktoc(temp);
	cout << c << " - C\n";	
	double f = ctof(temp);
	cout << f << " - F\n";
	double f2c = ftoc(temp);
	cout << f2c << " - F2C\n";

}