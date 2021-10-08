#include "../std_lib_facilities.h"

int main()
{
	double a, b;
	double legkisebb = numeric_limits<double>::max();
	double legnagyobb = numeric_limits<double>::lowest();

	cout << "Írj be 2 db számot:\n";
	while(cin >> a >> b)
	{
		if (a < b)
			cout << "The smaller value is: " << a << " The larger value is: " << b << endl;
		else if (a > b)
			cout << "The smaller value is: " << b << " The larger value is: " << a << endl;
		else
			cout << "The numbers are equal\n";

		if (abs(a - b) < 0.01 && a != b)
			cout << "The numbers are almost equal\n";
		cout << "Írj be 2 db számot:\n";
	}
	return 0;
}