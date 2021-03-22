#include "../../std_lib_facilities.h"

int main() {
	vector<string> vDictionary;
	vector<string> vCensors{ "Apple","Banana" };
	bool bCensored = false;
	for (string temp; cin >> temp;) {
		vDictionary.push_back(temp);
	}

	sort(vDictionary);

	for (int i = 0; i < vDictionary.size(); ++i) {
		bCensored = false;
		for (int x = 0; x < vCensors.size(); ++x) {
			if (bCensored)
				break;
			else if(vDictionary[i] == vCensors[x]) {
				bCensored = true;
			}
		}
		if (bCensored)
			cout << "Censored\n";
		else if  (i == 0 || vDictionary[i - 1] != vDictionary[i])
			cout << vDictionary[i] << "\n";
	}

}