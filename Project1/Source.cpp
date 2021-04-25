#include "MyDate.h"
#include <iostream>

int main()
{
	mydate::Date birthday(1992, mydate::Month::dec, 31);

	if (mydate::leapyear(birthday.year()))
		std::cout << "Leap year";
	else
		std::cout << "Not a leap year";
	
	birthday.incmonth(6);

	std::cout << "birthday +6 months" << birthday;
}