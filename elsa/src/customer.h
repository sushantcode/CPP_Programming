#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <iostream>
#include <string>

class Customer{
	public:
		Customer(std::string name, std::string phone, std::string email);
		friend std::ostream& operator<<(std::ostream& ost, const Customer& cust);
		
	private:
		std::string _name;
		std::string _phone;
		std::string _email;
};
#endif
