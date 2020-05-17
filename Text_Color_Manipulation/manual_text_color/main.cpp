/* Sushant Gupta 1001520302 */
/* This program prints given text and command in the representative color. */

#include "color.h"

int main(){
	Color reset;
	Color red{255,0,0}, green{0,128,0}, purple{95,0,135};
	std::cout << red << "Red" << "\n" << green << "Green" << "\n" << purple << "Purple" << "\n" << reset << std::endl;
	Color user_input;
	std::cout << "Enter your color as '(Red, Green, Blue)': ";
	std::cin >> user_input;
	std::cout << user_input << user_input.to_string() << std::endl;
}
