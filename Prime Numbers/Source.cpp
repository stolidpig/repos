#include "../../std_lib_facilities.h"

vector<int> vPrimes = { 2 };

bool isPrime(int x) {

	bool bResult = false;
	for (int i = 0; i < vPrimes.size(); ++i)
	{ 
		if (x % vPrimes[i] == 0)	// If there is no remainder
		{
			bResult = false;		// Cannot be prime
			return bResult;			// Do not continue to check if prime
		}
		else if (x % vPrimes[i] != 0)
		{
			bResult = true;			// Could be prime
			if (i+1 == vPrimes.size())
				return bResult;
		}
	}
}

int main() {

	int iLimit = 0;
	cout << "What is your limit?\n";
	cin >> iLimit;
	int iCount = 0;
	for (int x = 2; iCount < iLimit; ++x) { // Keep checking for primes until there are iLimit primes
		if (isPrime(x))
		{
			vPrimes.push_back(x);
			cout << x << " is prime\n";
			iCount++;
		}
	}
	for (int i = 0; i < iCount; ++i)
	{
		// cout << vPrimes[i] << " ";
	}
}