#include "../std_lib_facilities.h"

void print_array(ostream& os, int* a, int n)
{
	for(int i = 0; i < n; ++i)
		os << a[i] << " ";
	os << endl;
}

int main()
{
	int* szam = new int;
	szam[0] = 7;
	int* p1 = szam;
	cout << "Value of p1: " << p1 << " pointed value: " << p1[0] << endl;

	int* kettosok = new int[7];
	for(int i = 0; i < 7; ++i)
		kettosok[i] = pow(2, i);

	int* p2 = kettosok;
	cout << "Value of p2: " << p2 << " pointed values: ";
	print_array(cout, p2, 7);

	int* p3 = p2;
	p2 = p1;
	p2 = p3;

	cout << "Value of p1: " << p1 << " pointed value: ";
	print_array(cout, p1, 1);
	cout << "Value of p2: " << p2 << " pointed values: ";
	print_array(cout, p2, 7);
	delete p1;
	delete[] p3;

	int* szamok10 = new int[10];
	for(int i = 0; i < 10; ++i)
		szamok10[i] = pow(2, i);
	p1 = szamok10;
	
	int* other10 = new int[10];
	p2 = other10;

	for (int i = 0; i < 10; ++i)
		p2[i] = p1[i];

	delete[] p1;
	delete[] p2;

	vector<int> vect_szamok10(10);

	for(int i = 0; i < 10; ++i)
		vect_szamok10[i] = pow(2, i);

	vector<int> vect_other10(10);

	vect_other10 = vect_szamok10;

	//vector<int>* vp1 = &vect_szamok10;

	return 0;
}