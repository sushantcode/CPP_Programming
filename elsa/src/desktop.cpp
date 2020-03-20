#include "desktop.h"

void Desktop::add_option(Options& option){
	options.push_back(&option);
}

double Desktop::price(){
	double sum = 0;
	for (auto o : options){
		sum = sum + o->_costs;
	}
	return sum;
}

std::ostream& operator<<(std::ostream& ost, const Desktop& desktop){
	ost << desktop.price();
	return ost;
}
