#include "ram.h"

Ram::Ram(std::string name, double cost, int gb)
	: Options{name, cost}, _gb{gb} { }

Ram::~Ram() { }

std::string Ram::to_string() const{
	std::ostringstream costStream;
	costStream << std::fixed << std::setprecision(2) << _cost;
	return _name + std::to_string(_gb) + "gb" + "($" + costStream.str() + ")";
}

std::ostream& Ram::to_print(std::ostream& ost) const {
	ost << to_string();
	return ost;
}

Ram::Ram(std::istream& ist)
	: Options(ist){
	std::string size;
	std::getline(ist, size);
	try{
	_gb = std::stoi(size);
	}catch(std::exception& e){}
}

void Ram::save(std::ostream& ost){
	ost << _name << std::endl;
	ost << _cost << std::endl;
	ost << _gb << std::endl;
}
