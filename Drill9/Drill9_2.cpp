#include "../std_lib_facilities.h"

constexpr int max_year = 2021;
constexpr int min_year = 0;


struct Date
{
	int y, m, d;
	Date(int y, int m, int d);
	void add_day(int n);
	void repair_date();
};

void repair_date(); //deklarálása

Date::Date(int y, int m, int d):
y(y),
m(m),
d(d)
{
	if (max_year < y || y < min_year)
		error("Invalid year in date");
	if (12 < m || m < 0)
		error("Invalid month in date");
	if (31 < d || d < 0)
		error("Invalid day in date");
}

void Date::add_day(int n)
{
	d += n;
	repair_date();
}

void Date::repair_date()
{
		while(d > 31)
		{
			d -= 31;
			m++;
		}
		while(d < 1)
		{
			d += 31;
			m--;
		}
		while(m > 12)
		{
			m -= 12;
			y++;
		}
		while(m < 1)
		{
			m += 12;
			y--;
		}
		Date(y, m, d);
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}

int main()
try 
{
	Date today {1978, 6, 25};
	Date tomorrow {today.y, today.m, today.d};
	tomorrow.add_day(1);
	cout << today << endl << tomorrow << endl;
}
catch(exception& e)
{
	cerr << "Error: " << e.what() << endl;
}