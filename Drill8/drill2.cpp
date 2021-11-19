#include "../std_lib_facilities.h"


void swap_v(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_r(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/*
void swap_cr(const int& a, const int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	// konstans referencia értéke nem módosítható
}
*/

int main()
{

int x = 7;
int y = 9;

swap_v(x, y);
cout << "swap_v(x, y) " << x << " " << y << endl;

swap_r(x, y);
cout << "swap_r(x, y) " << x << " " << y << endl;

swap_v(7, 9);

// swap_r(7, 9); // '7' és '9' nem változók (hanem literálok) ezért a referenciának nincs értelme

const int cx = 7;
const int cy = 9;

swap_v(cx, cy);
cout << "swap_v(cx, cy) " << cx << " " << cy << endl;
/*
swap_r(cx, cy);
// konstans változó értékét nem lehet megváltoztatni
*/

double dx = 7.7;
double dy = 9.9;

swap_v(dx, dy);
cout << "swap_v(dx, dy) " << dx << " " << dy << endl;
// swap_r(dx, dy); //double-re int referencia

swap_v(7.7, 9.9);
// swap_r(7.7, 9.9); // (nem változó) double-re int referencia

}