#include <iostream> 
#include <fstream> 
#include <sstream>
#include <string>
#include <vector>


void tolower(std::string& s)
{
	for (char& c : s) c = std::tolower(c);
}
void format(std::string& s)
{
	s.erase(std::remove_if(s.begin(), s.end(), ispunct), s.end());
	tolower(s);
}

int main()
{
	std::cout << "Enter Word\n";

	std::string userWord;
	std::cin >> userWord;
	tolower(userWord);

	std::cout << "Enter inputFile\n";
	std::string inputFile;
	std::cin >> inputFile;
	std::ifstream ifs{inputFile};
	if (!ifs.good())
		std::cout << "Error with " << inputFile << "\n";

	std::vector<std::vector<std::string>> vLines;
	
	for (std::string sLine; std::getline(ifs, sLine);)
	{
		std::stringstream ss{ sLine };
		std::vector<std::string> vLine;

		for (std::string word; ss >> word;)
		{
			format(word);
			vLine.push_back(word);
		}
		vLines.push_back(vLine);
	}

	for (int i=0; i < vLines.size();++i)
	{
		for (int y=0; y < vLines[i].size(); ++y)
		{
			if (vLines[i][y] == userWord)
			{
				std::cout << "Line " << i+1 << " contains " << userWord << "\n";
				break;
			}
		}
	}


	std::cout << "Enter outputFile\n";
	std::string outputFile;
	std::cin >> outputFile;
	std::ofstream ofs{ outputFile };
	if (!ofs.good())
		std::cout << "Error with " << outputFile << "\n";

}

