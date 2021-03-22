#include "../../std_lib_facilities.h"

int main() {
	cout << "Please enter your first name and age\n";
	string sFirstName;
	double dAge;
	cin >> sFirstName >> dAge;
	dAge = dAge * 12;
	cout << "Hello " << sFirstName << ", age: " << dAge << " months" << "!\n";
	return 0;
}