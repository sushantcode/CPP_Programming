#include "taxfree.h"

Taxfree::Taxfree(std::string name, double cost)
	: Product { }
	
virtual Taxfree::~Taxfree()

override double const Taxfree::price(){
	Product::price(){
		return _quantity*_cost;
	}
}
