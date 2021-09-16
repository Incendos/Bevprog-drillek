#include "../std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you want to write to:\n";
	string first_name;
	cin >> first_name;
	cout << "Dear, " << first_name <<"\n\n"<< "How are you? I am fine. I miss you.\n\nPlease tell me how are you doing. How was your summer holiday?\n";
	cout << "Please enter the name of another friend of yours:\n";
	string friend_name;
	cin >> friend_name;
	cout << "Have you seen " << friend_name << " lately?\n";
	char friend_sex = 0;
	cout << "What is your friend's gender? (male='m', female='f')\n";
	cin >> friend_sex;
	if (friend_sex=='m')
		cout << "If you see " << friend_name << " please ask him to call me\n";
	else cout << "If you see " << friend_name << " please ask her to call me\n";
	cout << "What is the age of your friend?\n";
	int age;
	cin >> age;
	if (age < 12) 
		cout << "Next year you will be" << age + 1 << "\n";
	else if (age > 70) cout << "I hope you are enjoying retirement\n";
	else if (age==17) cout << "Next year you will be able to vote\n";
	cout << "Yours sincerely,\n\n\nDimand Márton\n";
	return 0;
}