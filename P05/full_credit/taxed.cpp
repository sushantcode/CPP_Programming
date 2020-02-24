#include "taxed.h"

#define _tax 0.0825

Taxed::Taxed(std::string name, double cost)
	: Product, _tax{0} { }

virtual Taxed::~Taxed(){ }

static double Taxed::set_tax_rate(double sales_tax){
	_tax = sales_tax;
	return _tax;
}

override double const Taxed::price(){
	Product::price(){
		return _quantity*_cost*(1+_tax);
	}
}
