#include "taxfree.h"

Taxfree::Taxfree(std::string name, double cost)
	: Product(name, cost) { }
	
Taxfree::~Taxfree() { }

double const Taxfree::price(){
		return _quantity*_cost;
}

Product* Taxfree::clone(){
	return new Taxfree(*this);
}
