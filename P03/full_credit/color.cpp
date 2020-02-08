#include "color.h"


Color::Color(){ }

Color::Color(int red, int green, int blue)
	: _red{red}, _green{green}, _blue{blue} {
	if(_red > 255 || _red < 0) throw std::runtime_error{"Invalid red component!"};
	if(_green > 255 || _green < 0) throw std::runtime_error{"Invalid green component!"};
	if(_blue > 255 || _blue < 0) throw std::runtime_error{"Invalid blue component!"};
}

std::string Color::to_string(){
	std::string string_out;
	string_out = "(" + std::to_string(_red) + "," + std::to_string(_green) + "," + std::to_string(_blue) + ")";
	return string_out;
}
		
std::ostream& operator<<(std::ostream& ost, Color& color){
	ost << "\033[38;2;"+std::to_string(color._red)+";"+std::to_string(color._green)+";"+std::to_string(color._blue)+"m";
}

//Color::Color(int red, int green, int blue)
std::istream& operator>>(std::istream& ist, Color& color){
	ist >> color._red;
	ist >> color._green;
	ist >> color._blue;
	if(color._red > 255 || color._red < 0) throw std::runtime_error{"Invalid red component!"};
	if(color._green > 255 || color._green < 0) throw std::runtime_error{"Invalid green component!"};
	if(color._blue > 255 || color._blue < 0) throw std::runtime_error{"Invalid blue component!"};
}
