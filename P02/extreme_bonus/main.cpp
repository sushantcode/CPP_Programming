/* Sushant Gupta 1001520302 */
/* This program prints given text and command in the representative color including magnitude in color code. */

#include "color.h"

bool less_than(Color lhs, Color rhs){
	return lhs.compare(&rhs);
}

int main(){
	Color red{255,0,0}, green{0,128,0}, purple{95,0,135};
	std::cout << red.colorize("Red") << "\n" << green.colorize("Green") << "\n" << purple.colorize("Purple") << std::endl;
	int user_red, user_green, user_blue;
	std::cout << "Enter integers for red, green and blue components: ";
	std::cin >> user_red >> user_green >> user_blue;
	Color user_input{user_red,user_green,user_blue};
	std::cout << user_input.colorize(user_input.to_string()) << std::endl;
	//Color rhs{156,48,215};
	//std::cout << user_input.compare(&rhs) << std::endl;
	std::vector <Color> colors{{156,48,215}, {214,155,126}, {78,148,84}};
	std::sort (colors.begin(), colors.end(), less_than);
	
}
