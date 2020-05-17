#include "ram.h"

Ram::Ram(std::string name, double cost, int gb)
	: Options{name, cost}, _gb{gb} { }

Ram::~Ram() { }

std::string Ram::to_string() const{
	std::ostringstream costStream;
	costStream << std::fixed << std::setprecision(2) << _cost;
	return "RAM: " + std::to_string(_gb) + " gb " + _name + " ($" + costStream.str() + ")";
}

Ram::Ram(std::istream& ist)
	: Options(ist){
	std::string size;
	std::getline(ist, size);
	try{
		_gb = std::stoi(size);
	}catch(std::exception& e){
		throw std::runtime_error{"Ram Data Corrupted."};
	}
}

void Ram::save(std::ostream& ost){
	ost << "RAM\n";
	Options::save(ost);
	ost << _gb << std::endl;
}

Options* Ram::copy() {
	return new Ram{*this};
}
