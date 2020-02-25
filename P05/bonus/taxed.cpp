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

void Taxed::tester(std::string *name, double *cost, double *tax){
	*name = _name;
	*cost = _cost;
	*tax = _tax;
}
