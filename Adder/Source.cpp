#include "../../std_lib_facilities.h"

int main()
	{
	cout << "How many values do you want to sum?\n";
	int n = 0;
	if (!(cin >> n))
	{
		cout << "invalid input for n!\n";
	}
	vector<double> values = {};
	vector<double> differences = {};
	cout << "Please enter some integers with a `|` to stop.\n";
	for (double vtemp = 0; cin >> vtemp;)
	{
		values.push_back(vtemp);
	}
	if (values.size() != n)
	{
		cout << "quantity error";
	}
	else if (n == 1)
	{
		cout << "Result: " << values[0] << endl;
	}
	else
	{
		double result = 0;
		for (int i = 0; i < values.size(); ++i)
		{
			narrow_cast<double>(result += values[i]);
		}

		cout << "Result: " << result << endl;
		
		for (int i = 0; i < values.size() - 1; ++i)
		{
			differences.push_back(abs(values[i] - values[i + 1]));
		}
		cout << "Difference between inputs: ";
		for (int i = 0; i < differences.size(); ++i)
		{
			cout << differences[i] << " ";
		}
	}
}