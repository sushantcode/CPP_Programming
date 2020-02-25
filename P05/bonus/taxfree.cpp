#include "taxfree.h"

Taxfree::Taxfree(std::string name, double cost)
	: Product(name, cost) { }
	
Taxfree::~Taxfree() { }

double const Taxfree::price(){
		return _quantity*_cost;
}

void Taxfree::tester(std::string *name, double *cost){
	*name = _name;
	*cost = _cost;
}
