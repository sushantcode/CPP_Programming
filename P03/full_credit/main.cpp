/* Sushant Gupta 1001520302 */
/* This program prints given text and command in the representative color. */

#include "color.h"

int main(){
	Color red{255,0,0};
	/*std::cout << red.colorize("Red ") << green.colorize("Green ") << purple.colorize("Purple") << std::endl;
	int user_red, user_green, user_blue;
	std::cout << "Enter integers for red, green and blue components: ";
	std::cin >> user_red >> user_green >> user_blue;
	Color user_input{user_red,user_green,user_blue};*/
	std::cout << red << "Red" << "\033[0m" << std::endl;
}
