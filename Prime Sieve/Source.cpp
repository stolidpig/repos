#include <iostream>
#include <vector>
using namespace std;  // for learning purpose

void SieveOfEratosthenes(int n)
{
    vector<bool> prime = {};

    for (int i = 0; i <= n; ++i)
    {
        prime.push_back(true);
    }

    for (int p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}

int main()
{
    int max = 0;

    cout << "Enter your limit: \n";

    cin >> max;

    cout << "The following are the prime numbers smaller than or equal to " << max << "\n";
    SieveOfEratosthenes(max);
    return 0;
}