#include "../std_lib_facilities.h"

vector<int> gv {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

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

void f(vector<int> a)
{
vector<int> lv(a.size());

lv = gv;

for(const auto& i : lv)
	cout << i << " ";
cout << endl;

vector<int> lv2 = a;

for(const auto& i : lv2)
	cout << i << " ";
cout << endl;
}


int main()
{
	f(gv);
	vector<int> vv(10);
	for (int i = 0; i < 10; ++i)
		vv[i] = fact(i + 1);
	f(vv);
}