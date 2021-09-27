#include "../std_lib_facilities.h"

int main()
{
	string first_name = "", friend_name = "", letter = "";
	char friend_sex = 0;
	int age = 0;

	cout << "Enter the name of the person you want to write to:\n";
	cin >> first_name;
	letter = "Dear " + first_name + ",\n\n\tHow are you? I am fine. I miss you.\n";
	letter += "Please tell me how are you doing. How was your summer holiday?\n";
	
	cout << "Please enter the name of another friend of yours:\n";
	cin >> friend_name;
	letter += "Have you seen " + friend_name + " lately? ";
	
	cout << "What is your friend's gender? (male='m', female='f')\n";
	cin >> friend_sex;
	if (friend_sex == 'm')
		letter += "If you see " + friend_name + " please ask him to call me.\n";
	else 
		letter += "If you see " + friend_name + " please ask her to call me.\n";
	
	cout << "What is the age of your recipient?\n";
	cin >> age;
	if (age <= 0 || age >= 110)
		simple_error("you're kidding!");
	letter += "I hear you just had a birthday and you are " + to_string(age) + " years old.";
	if (age < 12)
		letter += "\nNext year you will be " + to_string(age + 1) + ".";
	else if (age > 70) 
		letter += "\nI hope you are enjoying retirement.";
	else if (age == 17) 
		letter += "\nNext year you will be able to vote.";

	letter += "\n\nYours sincerely,\n\n\nDimand Márton\n";
	cout << "Here is your whole letter:\n\n" << letter;
	return 0;
}