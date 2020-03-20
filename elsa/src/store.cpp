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
	options.push_back(&option);
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

int Store::num_desktop(){
	return desktops.size();
}

Desktop& Store::desktop(int index){
	return desktops.at(index);
}
