#include "../../std_lib_facilities.h"

int main()
{
	vector <int> vF = { 1,1 };
	int user=0;
	cout << "How many F numbers do you want?\n";
	cin >> user;
	if (user < 0)
		cout << "I don't think that was right!\n";
	else if (user < 3)
		for (int i = 0; i < user; ++i)
			cout << vF[i] << endl;
	else
	{
		for (int i = 0; i < user - 2; ++i)
			vF.push_back(vF[i] + vF[i + 1]);
		for (int i = 0; i < user; ++i)
			cout << vF[i] << " " << i << endl;
	}
}