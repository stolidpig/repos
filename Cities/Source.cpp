#include "../../std_lib_facilities.h"

int main() {

	vector<double> vDistances = {};
	double dSmallestDistance = DBL_MAX;
	double dLargestDistance = DBL_MIN;
	double dSum = 0;
	double dMeanDistance = 0;

	for (double dDistance; cin >> dDistance;) {
		vDistances.push_back(dDistance);
		dSum += dDistance;
		if (dDistance < dSmallestDistance) {
			dSmallestDistance = dDistance;
		}
		if (dDistance > dLargestDistance) {
			dLargestDistance = dDistance;
		}
	}
	
	dMeanDistance = dSum / vDistances.size();

	cout << "dSum is: " << dSum << "\n";
	cout << "dLargestDistance is: " << dLargestDistance << "\n";
	cout << "dSmallestDistance is: " << dSmallestDistance << "\n";
	cout << "dMeanDistance is: " << dMeanDistance << "\n";
}