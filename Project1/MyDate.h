#include <iostream>

namespace mydate {
	
	// Scoped enum
	enum class Month
	{
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	Month operator++(Month& m);

	class Date {
	public:
		class invalid {}; // For Errors

		Date(int yy, Month mm, int dd);
		Date(); // Default constructor
		// Default copy operations are acceptable
		
		// read only operations
		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }

		// write operations
		void incday(int n);
		void incmonth(int n);
		void incyear(int n);

	private:
		int y;
		Month m;
		int d;		
	};

	bool isdate(int y, Month m, int d);		// true for a valid date
	bool leapyear(int y);					// true if y is a leap year

	bool operator==(const Date& a, const Date& b);	// overloads for comparison
	bool operator!=(const Date& a, const Date& b);

	std::ostream& operator << (std::ostream& os, const Date& d);	// overloads for streams
	std::istream& operator >> (std::istream& is, Date& dd);

	//Day dayofweek(const Date& d);		// Named day of date d
	Date nextsunday(const Date& d);		// Next Sunday after date d
	Date nextweekday(const Date& d);	// Date of next weekday after date d
}