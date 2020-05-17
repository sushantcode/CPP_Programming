#include "customer.h"

Customer::Customer(std::string name, std::string phone, std::string email)
	: _name{name}, _phone{phone}, _email{email} { }

std::ostream& operator<<(std::ostream& ost, const Customer& cust){
	ost << cust._name << " (" << cust._phone << ", " << cust._email << ")";
	return ost;
}

Customer::Customer(std::istream& ist){
	std::getline(ist, _name);
	std::getline(ist, _phone);
	std::getline(ist, _email);
}

void Customer::save(std::ostream& ost){
	ost << _name << std::endl;
	ost << _phone << std::endl;
	ost << _email << std::endl;
}
