#ifndef _ORDER_H
#define _ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "desktop.h"
#include "customer.h"

class Order{
	public:
		Order(Customer& customer);
		~Order();
		int add_product(Desktop& desktop);
		double price() const;
		friend std::ostream& operator<<(std::ostream& ost, const Order& order);
		Order(std::istream& ist);
		void save(std::ostream& ost);
		
	private:
		Customer* _customer;
		std::vector<Desktop*> _products;
};
#endif
