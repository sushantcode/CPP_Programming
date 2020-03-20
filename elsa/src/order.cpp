#include "order.h"

Order::Order(Customer& customer)
	: _customer{customer}{ }

Order::~Order(){ }

int Order::add_product(Desktop& desktop){
	_products.push_back(&desktop);
}

double Order::price() const{
	double sum = 0;
	for (auto p : _products){
		sum = sum + p->price();
	}
	return sum;
}

std::ostream& operator<<(std::ostream& ost, const Order& order){
	ost << order.price();
	return ost;
}
