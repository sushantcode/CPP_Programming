#include "customer.h"
#include "store.h"

void Store::add_customer(Customer& customer){
	customers.push_back(customer);
}

int Store::num_customers(){
	return customers.size();
}

Customer& Store::customer(int index){
	return customers.at(index);
}
