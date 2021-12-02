#include "../std_lib_facilities.h"

int ga[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

int fact(int n)
{
	if (n < 0)
		error("negative number in fact()");
	if(n == 1)
		return n;
	if (n == 0)
		return 1;
	return n *= fact(n - 1);
}

void f(int a[], int s)
{

int la[10];

for (int i = 0; i < 10; ++i)
	{
		la[i] = ga[i];
		cout << la[i] << " ";
	}
cout << endl;

int* p = new int[s];

for(int i = 0; i < s; ++i)
	{
		p[i] = a[i];
		cout << p[i] << " ";
	}
cout << endl;

delete[] p;
}

int main()
{
	f(ga, 10);
	int aa[10];
	for (int i = 0; i < 10; ++i)
		aa[i] = fact(i + 1);
	f(aa, 10);
}