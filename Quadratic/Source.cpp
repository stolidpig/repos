#include "../../std_lib_facilities.h"

double fSolveforx1(double a, double b, double c) {
	double x = 0, d = 0, drt = 0;
	d = (b * b) - (4 * (a * c));
	drt = sqrt(d);
	x = (-b + drt) / (2 * a);
	return x;
}
double fSolveforx2(double a, double b, double c) {
	double x = 0, d = 0, drt = 0;
	d = (b * b) - (4 * (a * c));
	drt = sqrt(d);
	x = (-b - drt) / (2 * a);
	return x;
}

int main() {
	double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
	cout << "Welcome to the amazing quadrolver! Please input a, b and c respectively, with at least 1 decimal place each followed by a new line: \n";
	if (cin >> a >> b >> c)
	{
		cout << "Nice! Let's get freaky~\n";
	}
	else {
		cout << "Ouch, sorry homes";
	}
	x1 = fSolveforx1(a, b, c);
	x2 = fSolveforx2(a, b, c);

	cout << "Given " << a << "x^2 + " << b << "x + " << c << " = 0, your possible solutions for x are:\n"
		<< "x1 = " << x1 << endl
		<< "x2 = " << x2 << endl;
}