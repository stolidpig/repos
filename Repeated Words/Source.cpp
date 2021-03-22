#include "../../std_lib_facilities.h"

int main() 
{
	int iNumberOfWords = 0;
	string sPrevious = " ";
	string sCurrent;
	while (cin >> sCurrent) // Read a stream of words
	{
		++iNumberOfWords;
		if (sPrevious == sCurrent) // Check if the word is the same as the last
			cout << "Repeated word: " << sCurrent << " at word number: " << iNumberOfWords << '\n';
		sPrevious = sCurrent;
	}

}