#include "../std_lib_facilities.h"

struct Point
	{
		int x;
		int y;
	};
	
int main()
{	
	vector<Point> original_points(7);
	
	// beolvasás
	for(int i = 0; i < 7; i++)
		cin >> original_points[i].x >> original_points[i].y;
	
	// kiíratás
	cout << "original_points: " << endl;
	for(const auto& i : original_points)
		cout << i.x << " " << i.y << endl;

	// file-ba írás
	ofstream ofile{"mydata.txt"};
	for(const auto& i : original_points)
		ofile << i.x << " " << i.y << endl;
	ofile.close();

	// file-ból olvasás
	vector<Point> processed_points(7);
	ifstream ifile{"mydata.txt"};
	for (auto& i : processed_points)
		ifile >> i.x >> i.y;
	ifile.close();

	// kiíratás
	cout << "processed_points: " << endl;
	for(const auto& i : processed_points)
		cout << i.x << " " << i.y << endl;

	// ha nem egyenlő a 2
	for(int i = 0; i < 7; i++)
		if(original_points[i].x != processed_points[i].x || original_points[i].y != processed_points[i].y)
			cout << "Something's wrong!";

	return 0;	
}