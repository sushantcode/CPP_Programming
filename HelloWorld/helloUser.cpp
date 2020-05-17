/* This program find user's name from the terminal and prints out "Hello [User's name]!" on console output screen. */


#include <iostream>
#include <string>

using namespace std;

int main()
{
	string nam = getenv("USER"); //statement to deduce user's name
	
	cout << "Hello, " << nam << "!" << endl;

	return 0;
}
