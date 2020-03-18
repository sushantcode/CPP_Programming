#ifndef _STORE_H
#define _STORE_H

#include <vector>
#include "customer.h"

class Store{
	public:
		void add_customer(Customer& customer);
		int num_customers();
		Customer& customer(int index);
		
	private:
		std::vector<Customer> customers;
};

#endif
