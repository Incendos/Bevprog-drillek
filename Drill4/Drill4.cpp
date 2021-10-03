#include "../std_lib_facilities.h"

int main()
{
	double db_a, db_b;
	double legkisebb = numeric_limits<double>::max();
	double legnagyobb = numeric_limits<double>::lowest();

	string str_a, str_b;
	
	while(true)
	{
		cout << "Írj be 2 db számot:\n";

		cin >> str_a;
		if (str_a == "|")
			break;
		cin >> str_b;
		if (str_b == "|")
			break;

		db_a = stod(str_a);
		db_b = stod(str_b);

		if (db_a < db_b)
			cout << "The smaller value is: " << db_a << " The larger value is: " << db_b << endl;
		else if (db_a > db_b)
			cout << "The smaller value is: " << db_b << " The larger value is: " << db_a << endl;
		else
			cout << "The numbers are equal\n";

		if (abs(db_a - db_b) < 0.01 && db_a != db_b)
			cout << "The numbers are almost equal\n";
	}
	return 0;
}