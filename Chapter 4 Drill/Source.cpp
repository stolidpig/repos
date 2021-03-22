#include "../../std_lib_facilities.h"

double convertcentimeter(double x) {
	double result = x / 100;
	return result;
}
double convertinch(double x) {
	double result = convertcentimeter(x) * 2.54;
	return result;
}
double convertfoot(double x) {
	double result = convertinch(x) * 12;
	return result;
}

int main() {

	vector<double> vValues = {};

	cout << "I'm a basic distance tracking program! Enter a number and a unit\n";

	double dRunningTotal = 0;
	double dInput = 0;
	double dOutput = 0;
	double iSmallest = DBL_MAX;
	double iLargest = DBL_MIN;
	string unit = " ";

	while (cin >> dInput >> unit) {

		bool bValidUnit = true;

		cout << "You entered: " << dInput << unit + "\n";

		if (unit == "m") {
			dOutput = dInput;
		}
		else if (unit == "cm") {
			dOutput = convertcentimeter(dInput);
		}
		else if (unit == "in") {
			dOutput = convertinch(dInput);
		}
		else if (unit == "ft") {
			dOutput = convertfoot(dInput);
		}
		else {
			cout << "I don't know that unit!\n";
			bValidUnit = false;
		}

		if (bValidUnit) {
			vValues.push_back(dOutput);
			dRunningTotal += dOutput;
			if (dOutput > iLargest) {
				iLargest = dOutput;
				cout << "The largest so far!\n";
			}
			else if (dOutput < iSmallest) {
				iSmallest = dOutput;
				cout << "The smallest so far!\n";
			}
		}

	}
	
	cout << "The largest converted value was: " << iLargest << "\n";
	cout << "The smallest converted value was: " << iSmallest << "\n";
	cout << "The number of values entered was: " << vValues.size() << "\n";
	cout << "The sum of all values was: " << dRunningTotal << "\n";
	cout << "The converted input values were: ";

	sort(vValues);

	for (double i : vValues) {
		cout << vValues[i] << " ";
	}
}