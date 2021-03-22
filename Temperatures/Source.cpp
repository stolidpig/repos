#include "../../std_lib_facilities.h"

double median(vector<double> v) {

	int middle = v.size() / 2;

	if (v.size() % 2 == 0) 
	{
		return (v[middle] + v[middle - 1]) / 2;
	}
	else
	{
		return v[middle];
	}
}

int main() {
	vector<double> temps;
	for (double temp; cin >> temp;) {
		temps.push_back(temp);
	}
	// compute mean temperature
	double sum = 0;
	for (double x : temps) {
		sum += x;
	}
	cout << "Average temperature: " << sum / temps.size() << "\n";

	sort(temps);

	cout << "Median temperature: " << median(temps) << "\n";
}