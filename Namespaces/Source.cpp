#include <iostream>

namespace X
{
	int var = 0;
	void print()
	{
		std::cout << var << "\n";
	}
}

namespace Y
{
	int var = 0;
	void print()
	{
		std::cout << var << "\n";
	}
}

namespace Z
{
	int var = 0;
	void print()
	{
		std::cout << var << "\n";
	}
}

int main()
{
	X::var = 7;
	std::cout << "X var: ";
	X::print();
	using namespace Y;
	var = 9;
	std::cout << "Y var: ";
	print();
	{
		using Z::var; using Z::print;
		var = 11;
		std::cout << "Z var: ";
		print();
	}
	std::cout << "Y var: ";
	print();
	std::cout << "X var: ";
	X::print();
}