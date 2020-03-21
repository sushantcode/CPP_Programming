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

void Store::add_option(Options& option){
	options.push_back(new Options(option));
}

int Store::num_options(){
	return options.size();
}

Options& Store::option(int index){
	return *options.at(index);
}

int Store::new_desktop(){
	int curr_size = desktops.size();
	Desktop *newDesktop = new Desktop();
	desktops.push_back(*newDesktop);
	return curr_size;
}

void Store::add_option(int option, int desktop){
	(desktops.at(desktop)).add_option(*(options.at(option)));
}

int Store::num_desktops(){
	return desktops.size();
}

Desktop& Store::desktop(int index){
	return desktops.at(index);
}

int Store::new_order(int customer){
	int curr_size = orders.size();
	Order *newOrder = new Order(customers.at(customer));
	orders.push_back(*newOrder);
	return curr_size;
}

void Store::add_desktop(int desktop, int order){
	(orders.at(order)).add_product(desktops.at(desktop));
}

int Store::num_orders(){
	return orders.size();
}

Order& Store::order(int index){
	return orders.at(index);
}
