#include "product.h"

Product::Product(std::string name, double cost)
	: _name{name}, _cost{cost}, _quantity{0} {
	if(_cost < 0) throw std::runtime_error("Cost is negative!!");
}

Product::~Product() { }

void Product::set_quantity(int quantity){
	_quantity = quantity;
}

double const Product::price(){ }

std::ostream& operator<<(std::ostream& ost, const Product& product) {
	if (product._quantity == 0){
		ost << product._name + " ($" << std::fixed << std::setprecision(2) << product._cost << ")";
 	}
 	else {
 		ost << product._name + " (" << product._quantity << " @ $" << std::fixed << std::setprecision(2) << product._cost << ")";
 	}
 	return ost;
}
