#include "color.h"

Color::Color(){ 
	_reset = true;
}

Color::Color(int red, int green, int blue)
	: _red{red}, _green{green}, _blue{blue} {
	if(_red > 255 || _red < 0) throw std::runtime_error{"Invalid red component!"};
	if(_green > 255 || _green < 0) throw std::runtime_error{"Invalid green component!"};
	if(_blue > 255 || _blue < 0) throw std::runtime_error{"Invalid blue component!"};
	_reset = false;
}

std::string Color::to_string(){
	std::string string_out;
	string_out = "(" + std::to_string(_red) + "," + std::to_string(_green) + "," + std::to_string(_blue) + ")";
	return string_out;
}
		
std::ostream& operator<<(std::ostream& ost, Color& color){
	if (color._reset) {
	ost << "\033[0m";
	}
	else{
	ost << "\033[38;2;"+std::to_string(color._red)+";"+std::to_string(color._green)+";"+std::to_string(color._blue)+"m";
	}
	return ost;
}

std::istream& operator>>(std::istream& ist, Color& color){
	std::string user_input;
	char c;
	ist >> user_input;
	std::stringstream(user_input) >> c >> color._red >> c >> color._green >> c >> color._blue >> c;
	if(color._red > 255 || color._red < 0) throw std::runtime_error{"Invalid red component!"};
	if(color._green > 255 || color._green < 0) throw std::runtime_error{"Invalid green component!"};
	if(color._blue > 255 || color._blue < 0) throw std::runtime_error{"Invalid blue component!"};
		color._reset = false;
		return ist;
}
