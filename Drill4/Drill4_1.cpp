#include "../std_lib_facilities.h"

int main()
{
	double legkisebb = numeric_limits<double>::max();
	double legnagyobb = numeric_limits<double>::lowest();
	double number, osszeg = 0, darab = 0;
	string unit;
	vector<double> szamok;

	cout << "Írj be 1 db számot mértékegységgel (cm, m, in, ft):\n";

	while(cin >> number >> unit)
	{
		if (unit == "|")
			break;
		
		if (!(unit == "cm" || unit == "m" || unit == "in" || unit == "ft"))
			cout << "Illegal unit, try again\n";
		else 
		{
			//itt átvált méterbe és azt az értéket adja hozzá az összeghez és a vektor végéhez.
			switch(unit[0])
			{
				case 'm':
					osszeg += number;
					szamok.push_back(number);
					break;
				case 'c':
					osszeg += number/100;
					szamok.push_back(number/100);
					break;
				case 'i':
					osszeg += number*2.54/100;
					szamok.push_back(number*2.54/100);
					break;
				case 'f':
					osszeg += number*12*2.54/100;
					szamok.push_back(number*12*2.54/100);
					break;
			}
		

			cout << "n = " << number << " " << unit;

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