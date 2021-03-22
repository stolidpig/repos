#include "../../std_lib_facilities.h"

int main() {
	cout << "Please enter your first and second names\n";
	string sFirstName;
	string sSecondName;
	cin >> sFirstName >> sSecondName;
	string sFullName = sFirstName + ' ' + sSecondName;
	cout << "Hello " << sFullName << "!\n";
}