/* Sushant Gupta 1001520302 */
/* This program prints given text and command in the representative color. */

#include "color.h"

Color::Color(int red, int green, int blue)
	: _red{red}, _green{green}, _blue{blue} {
	if(_red > 255 || _red < 0) throw std::runtime_error{"Invalid red component!"};
	if(_green > 255 || _green < 0) throw std::runtime_error{"Invalid green component!"};
	if(_blue > 255 || _blue < 0) throw std::runtime_error{"Invalid blue component!"};
}

Color::~Color(){ }

std::string Color::to_string(){
	std::string string_out;
	string_out = "(" + std::to_string(_red) + "," + std::to_string(_green) + "," + std::to_string(_blue) + ")";
	return string_out;
}
		
std::string Color::colorize(std::string text){
	return "\033[38;2;"+std::to_string(_red)+";"+std::to_string(_green)+";"+std::to_string(_blue)+"m" + text + "\033[0m";
}

int main(){
	Color red{255,0,0}, green{0,128,0}, purple{95,0,135};
	std::cout << red.colorize("Red") << "\n" << green.colorize("Green") << "\n" << purple.colorize("Purple") << std::endl;
	int user_red, user_green, user_blue;
	std::cout << "Enter an integer representing Red: ";
	std::cin >> user_red;
	std::cout << "Enter an integer representing Green: ";
	std::cin >> user_green;
	std::cout << "Enter an integer representing Blue: ";
	std::cin >> user_blue;
	Color user_input{user_red,user_green,user_blue};
	std::cout << user_input.colorize(user_input.to_string()) << std::endl;
}
