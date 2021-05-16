#include <fstream>
#include <iostream>

int main() 
{
	std::string inputFileName;
	std::cin >> inputFileName;
	std::ifstream inputFile{ inputFileName };
	if (!inputFile.good())
		std::cout << "Error with: " << inputFileName << "\n";

	std::string outputFileName;
	std::cin >> outputFileName;
	std::ofstream outputFile{ outputFileName };
	if (!outputFile.good())
		std::cout << "Error with: " << outputFileName << "\n";

	for (char ch; inputFile >> ch;)
	{
		if (isalpha(ch))
		{
			ch = tolower(ch);
		}
		outputFile << ch;
	}

}