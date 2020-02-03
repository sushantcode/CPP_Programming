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
	string_out = "(" + std::to_string(_red) + "," + std::to_string(_green) + "," + std::to_string(_blue) + ":" + std::to_string(Color::magnitude()) + ")";
	return string_out;
}
		
std::string Color::colorize(std::string text){
	return "\033[38;2;"+std::to_string(_red)+";"+std::to_string(_green)+";"+std::to_string(_blue)+"m" + text + "\033[0m";
}

int Color::magnitude(){
	return (0.21*_red + 0.72*_green + 0.07*_blue);
}

int Color::compare(const Color* rhs){
	int this = Color::magnitude();
	if(this > *rhs){
		return 1;
	}
	else if(this == *rhs){
	       return 0;
	}
	else{
	       return -1;
	}
}
