#ifndef _STORE_H
#define _STORE_H

#include <vector>
#include "customer.h"
#include "options.h"
#include "desktop.h"

class Store{
	public:
		void add_customer(Customer& customer);
		int num_customers();
		Customer& customer(int index);
		void add_option(Options& option);
		int num_options();
		Options& option(int index);
		int new_desktop();
		void add_option(int option, int desktop);
		int num_desktop();
		Desktop& desktop(int index);
		
	private:
		std::vector<Customer> customers;
		std::vector<Options*> options;
		std::vector<Desktop> desktops;
};

#endif
