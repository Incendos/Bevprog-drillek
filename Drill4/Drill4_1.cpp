#include "../std_lib_facilities.h"

int main()
{
	string str_number = "", unit = "";

	double legkisebb = numeric_limits<double>::max();
	double legnagyobb = numeric_limits<double>::lowest();
	double db_number, osszeg = 0, darab = 0;

	vector<double> szamok;

	while(true)
	{
		cout << "Írj be 1 db számot mértékegységgel (cm, m, in, ft):\n";

		cin >> str_number;
		if (str_number == "|")
			break;
		cin >> unit;
		if (unit == "|")
			break;
		
		if (!(unit == "cm" || unit == "m" || unit == "in" || unit == "ft"))
			cout << "Illegal unit, try again\n";

		else 
		{
			db_number = stod(str_number);

			//itt átvált méterbe és azt az értéket adja hozzá az összeghez és a vektor végéhez.
			switch(unit[0])
			{
				case 'm':
					osszeg += db_number;
					szamok.push_back(db_number);
					break;
				case 'c':
					osszeg += db_number/100;
					szamok.push_back(db_number/100);
					break;
				case 'i':
					osszeg += db_number*2.54/100;
					szamok.push_back(db_number*2.54/100);
					break;
				case 'f':
					osszeg += db_number*12*2.54/100;
					szamok.push_back(db_number*12*2.54/100);
					break;
			}

			cout << "n = " << db_number << " " << unit;

			if (szamok[darab] <= legkisebb)
				{
					legkisebb = szamok[darab]; cout << " the smallest so far\n";
				}
			else if (szamok[darab] >= legnagyobb)
				{
					legnagyobb = szamok[darab]; cout << " the largest so far\n";
				}
				else cout << endl;

			darab++;
		}
	}

	cout << "Összesen " << darab << " értéket ütött be.\n";

	cout << "Ezen értékek összege: " << osszeg <<" m.\n";
	
	cout << "Az értékek amiket beütött:\n";
	sort(szamok);
	for (double i : szamok)
		cout << i << " m\n";
	
	return 0;
}