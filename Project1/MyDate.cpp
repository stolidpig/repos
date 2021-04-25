#include "MyDate.h"
#include <iostream>

namespace mydate
{
	// Definitions of mydate member functions
	Date::Date(int yy, Month mm, int dd)
		:y{ yy }, m{ mm }, d{ dd }
	{
		if (!isdate(yy, mm, dd) ) throw invalid{};
	}
	const Date& defaultdate()
	{
		static Date dd{ 2001,Month::jan,1 };
		return dd;
	}

	Date::Date()
		:y{ defaultdate().year() },
		m{ defaultdate().month() },
		d{ defaultdate().day() }
	{
	}
	void Date::incday(int n)
	{
		for (int i = 0; i < n; ++i)
		{
			int daysinmonth = 31;
			switch (m)
			{
			case Month::feb:
				daysinmonth = (leapyear(y)) ? 29 : 28;
				break;
			case Month::apr: case Month::jun: case Month::sep: case Month::nov:
				daysinmonth = 30;
				break;
			}
			if (d > daysinmonth)
			{
				incmonth(1);
				d = 1;
				break;
			};
			d++;
		}
	}
	void Date::incmonth(int n)
	{
		for (int i = 0; i < n; ++i)
		{
			if (m == Month::dec)y++;
			++m;
		}
		int daysinmonth = 31;
		switch (m)
		{
		case Month::feb:
			daysinmonth = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			daysinmonth = 30;
			break;
		}
		if (d > daysinmonth) d = daysinmonth;
		
	}
	void Date::incyear(int n)
	{	
		// In case current date is 29/feb and target is not a leap year
		if (m == Month::feb && d == 29 && !leapyear(y + n))
		{
			m = Month::mar;
			d = 1;
		}
		y += n;
	}
	
	// Helper functions

	Month operator++(Month& m)
	{
		m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
		return m;
	}

	bool isdate(int y, Month m, int d)
	{
		// We assume all years are valid

		if (d == 0) return false;

		if (m<Month::jan || m>Month::dec) return false;

		int daysinmonth = 31;
		switch (m)
		{
		case Month::feb:
			daysinmonth = (leapyear(y)) ? 29 : 28; 
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			daysinmonth = 30;
			break;
		}
		if (d > daysinmonth) return false;

		return true;
	}

	bool leapyear(int y)
	{
		if ((y % 4) != 0)
			return false;
		else if ((y % 100) != 0)
			return true;
		else if ((y % 400) != 0)
			return false;
		else
			return true;
	}

	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year() &&
			a.month() == b.month() &&
			a.day() == b.day();
	}

	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}

	std::ostream& operator << (std::ostream& os, const Date& d)
	{
		return os << '(' << d.year()
			<< ',' << int(d.month())
			<< ',' << d.day() << ')';
	}
	std::istream& operator >> (std::istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '('
			|| ch2 != ','
			|| ch3 != ','
			|| ch4 != ')')
		{
			is.clear(std::ios_base::failbit);
			return is;
		}
		dd = Date(y, Month(m), d);
		return is;
	}
	enum class Day {
		sunday,monday,tuesday,wednesday,thursday,friday,saturday
	};

	/*Day dayofweek(const Date& d)
	{
		// ...
	}

	Date nextsunday(const Date& d)
	{
		// ...
	}

	Date nextweekday(const Date& d)
	{
		// ...
	}*/
}