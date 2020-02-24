#include "product.h"

Product::Product(std::string name, double cost)
	: _name{name}, _cost{cost}, _quantity{0} {
	if(_cost < 0) throw std::runtime_error("Cost is negative!!");
}

virtual Product::~Product() { }

void Product::set_quantity(int quantity){
	_quantity = quantity;
}

virtual double const Product::price(){ }

std::ostream& operator<<(ostream& ost, const Product& product) {
	if (_quantity == 0){
		ost << product._name + " ($" + std::to_string(product._cost) + ")";
 	}
 	else {
 		ost << product._name + " ($" + std::to_string(product._quantity)+ "@" +  std::to_string(product._cost) + ")";
 	}
 	return ost;
}
