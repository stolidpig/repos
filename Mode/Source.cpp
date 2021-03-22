#include "../../std_lib_facilities.h"

int fFindMode(vector <int> Sequence)
{
	sort(Sequence);
	int highestcount = 0;
	int currentmode = 0;
	int currentmodecount = 0;

	for (int x = 0; x < Sequence.size() - 1; ++x)
	{
		currentmodecount = 1;

		for (int i = x + 1; i < Sequence.size() - 1; ++i)
		{
			if (Sequence[x] == Sequence[i])
			{
				currentmodecount++;
			}
			else
			{
				if (currentmodecount > highestcount)
				{
					highestcount = currentmodecount;
					currentmode = Sequence[x];
					cout << "current highest count is:" << highestcount << endl;
				}
				break;
			}

		}
	}
	return currentmode;
}

int main() {
	vector <int> Test = { 1,1,1,1,2,2,5,5,5,5,6,6,6,1,5,5 };
	cout << "Mode is:" << fFindMode(Test) << endl;
	cout << "Done";
}