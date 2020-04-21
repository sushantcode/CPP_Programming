#include "ram.h"

Ram::Ram(std::string name, double cost, int gb)
	: Options(name, cost), _gb{gb} {
	
}

Ram::~Ram() {

}

std::string Ram::to_string() const override{
	
}

Ram::Ram(std::istream& ist){

}

void Ram::save(std::ostream& ost) override{

}
