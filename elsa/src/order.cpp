#include "order.h"

Order::Order(Customer& customer)
	: _customer{customer}{ }

Order::~Order(){ }

int Order::add_product(Desktop& desktop){
	_products.push_back(new Desktop(desktop));
}

double Order::price() const{
	double sum = 0;
	for (auto p : _products){
		sum = sum + p->price();
	}
	return sum;
}

std::ostream& operator<<(std::ostream& ost, const Order& order){
	ost << "Customer: " << order._customer << "\n";
	for (auto p : order._products){
		ost << *p;
	}
	ost << "\nTotal price: " << std::fixed << std::setprecision(2) << order.price();
	return ost;
}
