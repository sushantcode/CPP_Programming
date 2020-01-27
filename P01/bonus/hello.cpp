/* This program simply prints out "Hello [My name]!" on console output screen. */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string nam;
	cout << "Enter your name: ";
	getline(cin, nam);
	cout << "Hello, " << nam << "!" << endl;

	return 0;
}
