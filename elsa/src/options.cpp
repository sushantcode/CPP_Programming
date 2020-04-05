#include "options.h"
#include <iomanip>
#include <sstream>

Options::Options(std::string name, double cost)
	: _name{name}, _cost{cost} { }
	
Options::~Options() { }

double Options::cost(){
	return _cost;
}

std::string Options::to_string() const{
	std::ostringstream costStream;
	costStream << std::fixed << std::setprecision(2) << _cost;
	return _name + " ($" + costStream.str() + ")";
}

std::ostream& operator<<(std::ostream& ost, const Options& option){
	ost << option.to_string();
	return ost;
}

Options::Options(std::istream& ist){ }

void Options::save(std::ostream& ost){ }
