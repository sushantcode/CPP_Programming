#include "taxed.h"

double Taxed::_tax;

Taxed::Taxed(std::string name, double cost)
	: Product(name, cost){ }

Taxed::~Taxed(){ }

void Taxed::set_tax_rate(double sales_tax){
	_tax = sales_tax;
}

double const Taxed::price(){
	return ((double)_quantity * _cost) + ((double)_quantity * _cost * _tax);
}

Product* Taxed::clone(){
	return new Taxed(*this);
}
