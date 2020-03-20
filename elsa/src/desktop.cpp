#include "desktop.h"

void Desktop::add_option(Options& option){
	options.push_back(&option);
}

double Desktop::price() const{
	double sum = 0;
	for (auto o : options){
		sum = sum + o->cost();
	}
	return sum;
}

std::ostream& operator<<(std::ostream& ost, const Desktop& desktop){
	ost << desktop.price();
	return ost;
}
