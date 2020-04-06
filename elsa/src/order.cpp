#include "order.h"

Order::Order(Customer& customer){
	_customer = new Customer(customer);
 }

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
	ost << "Customer: " << *(order._customer) << "\n";
	for (auto p : order._products){
		ost << *p;
	}
	ost << "\nTotal price: " << std::fixed << std::setprecision(2) << order.price();
	return ost;
}

Order::Order(std::istream& ist){
	_customer = new Customer(ist);
	std::string psize;
	std::getline(ist, psize);
	for (int i = 0; i < std::stoi(psize); i++){
		_products.push_back(new Desktop(ist));
		if(!ist) throw std::runtime_error{"Error opening option file"};
	}
}

void Order::save(std::ostream& ost){
	_customer->save(ost);
	ost << _products.size() << std::endl;
	for (auto p : _products){
		p->save(ost);
	}
}
