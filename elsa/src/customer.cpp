#include "customer.h"

Customer::Customer(std::string name, std::string phone, std::string email)
	: _name{name}, _phone{phone}, _email{email} { }

std::ostream& operator<<(std::ostream& ost, const Customer& cust){
	ost << cust._name << " " << cust._phone << " " << cust._email;
	return ost;
}
