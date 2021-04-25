#include "MyDate.h"
#include <Windows.h>
#include <iostream>

int main()
{
	mydate::Date birthday(1992, mydate::Month::dec, 31);

	if (mydate::leapyear(birthday.year()))
		std::cout << "Leap year";
	else
		std::cout << "Not a leap year";
	
	while (true)
	{
		birthday.incday(1);
		std::cout <<  birthday << "\n";
		Sleep(50);
	}
}