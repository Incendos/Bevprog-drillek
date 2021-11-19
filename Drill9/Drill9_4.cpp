#include "../std_lib_facilities.h"

class Year
{
	static const int min = 1800;
	static const int max = 2200;
public:
	class Invalid{};
	Year(int x): y{x} {if (x < min || max < x) throw Invalid{};}
	int year() const {return y;}
	void set_year(int year) {y = year;}
private:
	int y;
};

enum class Month
{
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

class Date
{
	Year y;
	Month m;
	int d;
public:
	class Invalid{};
	Date(Year a, Month b, int c): y{a}, m{b}, d{c} {if(!is_valid()) throw Invalid{};} 
	bool is_valid();
	void add_day(int n);
	int year() const {return y.year();}
	int month() const {return int(m);}
	int day() const {return d;}
};

Month operator++(Month& m)
{
	m = (m == Month::Dec) ? Month::Jan : Month(int(m) + 1);
	return m;
}

Month operator--(Month& m)
{
	m = (m == Month::Jan) ? Month::Dec : Month(int(m) - 1);
	return m;
}

bool Date::is_valid()
{
	if (int(m) > 12 || 1 > int(m))
		return false;
	if (d > 31 || 1 > d)
		return false;
	return true;
}

void Date::add_day(int n)
{
	d += n;
	int n_month = int(m);
	while(d > 31)
	{
		d -= 31;
		++m;
		++n_month;
	}
	while(d < 1)
	{
		d += 31;
		--m;
		--n_month;
	}
	while(n_month > 12)
	{
		n_month -= 12;
		y.set_year(y.year() + 1);
	}
	while(n_month < 1)
	{
		n_month += 12;
		y.set_year(y.year() - 1);
	}
	Date(Year{y.year()}, m, d);
	// az év kicsúszhat a valid intervallumból ezért lekell ellőrizni
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

int main()
try 
{
	Date today {Year{1978}, Month::Jun, 25};
	Date tomorrow {Year{today.year()}, Month(today.month()), today.day()};
	tomorrow.add_day(1);
	cout << today << endl << tomorrow << endl;
	return 0;
}
catch(exception& e)
{
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch(Date::Invalid& e)
{
	cerr << "Error: Invalid date" << endl;
	return 2;
}
catch(Year::Invalid& e)
{
	cerr << "Error: Invalid year" << endl;
	return 3;
}