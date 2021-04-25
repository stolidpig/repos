#include "../../std_lib_facilities.h"

const char number = '8';
const char quit = 'q';
const char print = '=';

class token 
{
public:
	char kind;
	double value;
	token(char ch)
		:kind(ch), value(0) {}
	token(char ch, double val)
		:kind(number), value(val) {}
private:

};

class tstream
{
public:
	tstream()
		:full(false), buffer(0) {}
	void putback(token t);
	token get();
private:
	token buffer;
	bool full;
};

void tstream::putback(token t)
{
	if (full) error("putback() to full buffer");
	buffer = t;
	full = true;
}

token tstream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}

	char ch = 0;
	cin >> ch;

	switch (ch) {
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return token(number, val);
	}
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case print:
	case quit:
	{
		return token(ch);
	}
	default:
		error("Bad input to tstream");
	} 
}

tstream ts;

class variable {
	public:
	string name;
	double value;
};

vector<variable> var_table;

double getvalue(string s)
{
	for (const variable& v : var_table)
	{
		if (v.name == s)
			return v.value;
	}
	error("get: undefined variable", s);
}

void setvalue(string s, double d)
{
	for (variable& v : var_table)
	{
		if (v.name == s) {
			v.value = d;
			return;
		}
	}
	error("set: undefined variable", s);
}

double expression();

double primary()
{
	token t = ts.get();

	while (true)
	{
		switch (t.kind)
		{
		case '(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')')
				error("')' expected");
			return d;
		}
		case number:
			return t.value;
		default:
			error("Bad Token in Primary");
		}
	}
};

double term()
{
	double left = primary();
	token t = ts.get();

	while (true)
	{
		switch (t.kind)
		{
		case '/':
		{
			double d = primary();
			if (d == 0)
				error("Divide by 0");
			left /= d;
			t = ts.get();
			break;
		}
		case '*':
			left *= primary();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
};

double expression()
{
	double left = term();
	token t = ts.get();

	while (true)
	{
		switch (t.kind)
		{
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
};

int main() {
	int val = 0;
	try 
	{
		while (cin)
		{
			token t = ts.get();
			while (t.kind == print) t = ts.get();
			if (t.kind == quit)
			{
				keep_window_open();
				return 0;
			}
			ts.putback(t);
			cout << "= " << expression();
		}
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		keep_window_open();
		return 2;
	}
}