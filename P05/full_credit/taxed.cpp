#include "taxed.h"

double Taxed::_tax = 0;

Taxed::Taxed(std::string name, double cost)
	: Product(name, cost){ }

Taxed::~Taxed(){ }

void Taxed::set_tax_rate(double sales_tax){
	_tax = sales_tax;
}

double const Taxed::price(){
	return (_quantity * _cost) + (_quantity * _cost * _tax);
}
