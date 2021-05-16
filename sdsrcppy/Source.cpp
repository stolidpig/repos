#include <iostream>



int main()
{
	bool exit = false;

	while (!exit)
	{
		std::cout << "Choose a Citrix endpoint:\n"
			<< "1 - BrightonXA01\n"
			<< "2 - BrightonXA02\n"
			<< "3 - BrightonXA03\n"
			<< "4 - LondonXA01\n"
			<< "5 - LondonXA02\n"
			<< "6 - LondonXA03\n"
			<< "Q - Quit\n";

		for (char ch; std::cin.get(ch);)
		{
			switch (ch)
			{
			case 'q':case 'Q':
				exit = true;
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
				std::cout << ch;
				break;
			}
			break;
		}
	}

}