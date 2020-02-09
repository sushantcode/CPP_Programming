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

int Color::magnitude(){
	return (0.21*(double)_red + 0.72*(double)_green + 0.07*(double)_blue);
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

bool Color::operator>=(Color& rhs){
	return compare(&rhs);
}

bool Color::operator<(Color& rhs){
	return (Color::magnitude() < rhs.magnitude());
}

bool Color::operator<=(Color& rhs){
	return ((Color::magnitude() < rhs.magnitude()) || (Color::magnitude() <= rhs.magnitude()));
}

bool Color::operator==(Color& rhs){
	return (Color::magnitude() == rhs.magnitude());
}

bool Color::operator!=(Color& rhs){
	return (Color::magnitude() != rhs.magnitude());
}

bool Color::operator>(Color& rhs){
	return (Color::magnitude() > rhs.magnitude());
}

bool Color::compare(const Color *rhs){
	int thisObj = Color::magnitude();
	int rhsObj = (0.21*(double)(rhs->_red) + 0.72*(double)(rhs->_green) + 0.07*(double)(rhs->_blue));
	if(thisObj > rhsObj || thisObj == rhsObj){
		return true;
	}
	else{
	       return false;
	}
}
