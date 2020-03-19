#include "options.h"
#include <iomanip>

Options::Options(std::string name, double cost)
	: _name{name}, _cost{cost} { }
	
Options::~Options() { }

double Options::cost(){
	return _cost;
}

std::string Options::to_string() const{
	return _name + " costs " + std::to_string(_cost);
}

std::ostream& operator<<(std::ostream& ost, const Options& option){
	ost << option.to_string();
	return ost;
}
