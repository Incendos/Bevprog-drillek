#include "../std_lib_facilities.h"

constexpr int max_year = 2021;
constexpr int min_year = 0;

struct Date
{
	int y;
	int m;
	int d;
};

void init_day(Date& dd, int y, int m, int d)
{
	if (max_year < y || y < min_year)
		error("Invalid year in date");
	if (12 < m || m < 0)
		error("Invalid month in date");
	if (31 < d || d < 0)
		error("Invalid day in date");
	
	dd.y = y;
	dd.m = m;
	dd.d = d;
}

void repair_date(Date& dd)
{
		while(dd.d > 31)
		{
			dd.d -= 31;
			dd.m++;
		}
		while(dd.d < 1)
		{
			dd.d += 31;
			dd.m--;
		}
		while(dd.m > 12)
		{
			dd.m -= 12;
			dd.y++;
		}
		while(dd.m < 1)
		{
			dd.m += 12;
			dd.y--;
		}
		init_day(dd, dd.y, dd.m, dd.d);
}

void add_day(Date& dd, int n)
{
	dd.d += n;
	repair_date(dd);
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}

int main()
try 
{
	Date today;
	init_day(today, 1978, 6, 25);
	Date tomorrow;
	init_day(tomorrow, today.y, today.m, today.d);
	add_day(tomorrow, 1);
	cout << today << endl << tomorrow << endl;
}
catch(exception& e)
{
	cerr << "Error: " << e.what() << endl;
}