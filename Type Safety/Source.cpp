#include "../../std_lib_facilities.h"

int main() {
	double d = 0;
	while (cin >> d) {

		int i1 = d;
		char c = i1;
		int i2 = c;
		cout << "d == " << d
			<< "\ni1 == " << i1
			<< "\ni2 == " << i2
			<< "\nchar(" << c << ")\n";
	}
}