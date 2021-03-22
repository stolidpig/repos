#include "../../std_lib_facilities.h"

class Bad_Input {};

void fNewGame(int iGameLength, vector<int> &vSolution) {

	// valid game length 1...9
	if (iGameLength < 1 || iGameLength > 9)
		throw Bad_Input{};
	
	vector<int> set = { 1,2,3,4,5,6,7,8,9,0 };
	
	// to shuffle our 'set'
	std::random_device rd;
	auto rng = std::default_random_engine{ rd() };

	for (int i = 0; i < iGameLength; ++i)
	{
		shuffle(set.begin(), set.end(), rng);	// shuffle set
		vSolution.push_back(set.back());		// add last element of set to solution vector
		set.pop_back();							// remove last element of set
	}
}

int fGetUserInput(int iGameLength, vector<int> &vUser)
{
	for (string input = " "; cin >> input;)		// read input to a string
	{
		int intin = 0;			
		if (input == "quit")					// user has requested quit
		{
			return 1;							// return value for quit
		}
		else try								// check input is a number		
		{
			intin = std::stoi(input);
		}
		catch (const std::exception&)
		{
			throw Bad_Input{};
		}		
		if (intin < 0 || intin > 9)				// check input is a valid integer
			throw Bad_Input{};
		else
		{
			vUser.push_back(intin);				// add to user solution
			if (vUser.size() > 1)				// check not a repeating number
			{
				for (int i = 0; i < vUser.size() - 1; ++i)
				{
					if (intin == vUser[i])		
						throw Bad_Input{};
				}
			}
			else if (vUser.size() == iGameLength)	// check if the user solution is "full"
				return 0;							// success return value
		}
	}
}

int main()
{
	int iGameLength = 0;
	vector<int> vSolution = {};
	cout << "What is your desired game length?\n";	// Game length will be the size of our solution vector and therefore the game difficulty
	cin >> iGameLength;
	
	// Main logic loop with error handling
	try
	{
		fNewGame(iGameLength, vSolution);	// Create a new game based on the users input 
		bool quit = false;					// Basic main loop flag
		while (!quit)
		{
			int bulls = 0;	// Score
			int cows = 0;

			vector<int> vUser = {}; // Vector that will contain the users input guess

			cout << "Enter " << iGameLength << " values or 'quit' to end: \n";

			if (fGetUserInput(iGameLength, vUser) > 0)		// Return value > 0 indicates user requested quit
			{
				cout << "Bye!\n";
				break;
			} 
			else {											// Input is valid
				for (int x = 0; x < iGameLength; ++x)
				{
					for (int y = 0; y < iGameLength; ++y)	// Total users score via bulls and cows logic
						if (vUser[x] == vSolution[y])
							if (x == y)
								++bulls;
							else
								++cows;
				}

				if (bulls == iGameLength)					// All bulls, victory, end loop
				{
					cout << "You win!\n";
					quit = true;
				}
				else										// Output score and repeat loop
				{
					cout << bulls << " bulls " << cows << " cows.\n";
				}
			}
		}
		return 0;							// Program has ended intentionally
	} 
	catch (Bad_Input)
	{
		cerr << "bad input\n";
		return 1;
	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << endl;
		return 2;
	}
	catch (...)
	{
		cerr << "unknown exception\n";
		return 3;
	}

}