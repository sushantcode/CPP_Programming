#include "disk.h"

Disk::Disk(std::string name, double cost, int tb)
	: Options{name, cost}, _tb{tb} { }

Disk::~Disk() { }

std::string Disk::to_string() const{
	std::ostringstream costStream;
	costStream << std::fixed << std::setprecision(2) << _cost;
	return "Disk: " + std::to_string(_tb) + " TB " + _name + " ($" + costStream.str() + ")";
}

Disk::Disk(std::istream& ist)
	: Options(ist){
	std::string size;
	std::getline(ist, size);
	try{
	_tb = std::stoi(size);
	}catch(std::exception& e){}
}

void Disk::save(std::ostream& ost){
	Options::save(ost);
	ost << _tb << std::endl;
}
