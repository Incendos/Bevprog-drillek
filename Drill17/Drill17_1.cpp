#include "../std_lib_facilities.h"

void print_array10(ostream& os, int* a)
{
	for(int i = 0; i < 10; ++i)
		os << a[i] << " ";
	os << endl;
}

void print_array(ostream& os, int* a, int n)
{
	for(int i = 0; i < n; ++i)
		os << a[i] << " ";
	os << endl;
}

void print_vector(ostream& os, vector<int> a)
{
	for(const auto& i : a)
		cout << i << " ";
	cout << endl;
}

int main()
{
	int* szamok = new int[10];
	print_array10(cout, szamok);
	delete[] szamok;

	int* hundreds = new int[10];
	for(int i = 0; i < 10; ++i)
		hundreds[i] = 100 + i;
	print_array10(cout, hundreds);
	delete[] hundreds;

	int* szamok11 = new int[11];
	for(int i = 0; i < 11; ++i)
		szamok11[i] = 100 + i;
	print_array(cout, szamok11, 11);
	delete[] szamok11;

	int* szamok20 = new int[20];
	for(int i = 0; i < 20; ++i)
		szamok20[i] = 100 + i;
	print_array(cout, szamok20, 20);
	delete[] szamok20;

	vector<int> vect_szamok10(10);
	for(int i = 0; i < 10; ++i)
		vect_szamok10[i] = 100 + i;
	print_vector(cout, vect_szamok10);

	vector<int> vect_szamok11(11);
	for(int i = 0; i < 11; ++i)
		vect_szamok11[i] = 100 + i;
	print_vector(cout, vect_szamok11);

	vector<int> vect_szamok20(20);
	for(int i = 0; i < 20; ++i)
		vect_szamok20[i] = 100 + i;
	print_vector(cout, vect_szamok20);

	return 0;
}