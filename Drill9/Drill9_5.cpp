#include "../std_lib_facilities.h"

enum class Month
{
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

class Date
{
	int y;
	Month m;
	int d;
public:
	class Invalid{};
	Date(int a, Month b, int c): y{a}, m{b}, d{c} {if(!is_valid()) throw Invalid{};} 
	bool is_valid();
	void add_day(int n);
	void add_month(int n);
	void add_year(int n);
	void repair_date();
	int year() const {return y;}
	int month() const {return int(m);}
	int day() const {return d;}
};

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

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
	if (y > 2200 || 1800 > y)
		return false;
	if (int(m) > 12 || 1 > int(m))
		return false;
	if (d > 31 || 1 > d)
		return false;
	return true;
}

void Date::repair_date()
{
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
		y++;
	}
	while(n_month < 1)
	{
		n_month += 12;
		y--;
	}
	if (!is_valid())
		throw Invalid{};
	// az év kicsúszhat a valid intervallumból ezért lekell ellőrizni
}

void Date::add_day(int n)
{
	d += n;
	repair_date();
}

void Date::add_month(int n)
{
	add_day(n*31);
}

void Date::add_year(int n)
{
	y += n;
	if (!is_valid())
		throw Invalid{};
	// az év kicsúszhat a valid intervallumból ezért lekell ellőrizni
}

int main()
try 
{
	Date today {1978, Month::Jun, 25};
	Date tomorrow {today.year(), Month(today.month()), today.day()};
	tomorrow.add_day(1);
	cout << today << endl << tomorrow << endl;
	return 0;
}
catch(Date::Invalid& e)
{
	cerr << "Error: Invalid date" << endl;
	return 1;
}