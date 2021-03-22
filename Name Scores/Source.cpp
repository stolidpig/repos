#include "../../std_lib_facilities.h"

bool fStringInVector(vector<string> vs, string s)
{
	bool bStringInVector = false;
	for (int i=0;i<vs.size();++i)
	{
		if (s == vs[i]) {
			bStringInVector = true;
			break;
		}
	}
	return bStringInVector;
}

bool fIntInVector(vector<int> vx, int x)
{
	bool bIntInVector = false;
	for (int i = 0; i < vx.size(); ++i)
	{
		if (x == vx[i]) {
			bIntInVector = true;
			break;
		}
	}
	return bIntInVector;
}

int main() {

	vector<int> vScores = {};
	vector<string> vNames = {};

	string tempname = "";
	int tempscore = 0;
	while (cin >> tempname >> tempscore)
	{
		if (tempname == "NoName" && tempscore == 0)
			break;
		else if (fStringInVector(vNames, tempname))
		{
			cout << "Error\n";
			break;
		}
		else
		{
				vScores.push_back(tempscore);
				vNames.push_back(tempname);
		}
	}
}