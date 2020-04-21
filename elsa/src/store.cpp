#include "store.h"

Store::Store(){ }

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
	return *(options.at(index));
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

Store::Store(std::istream& ist){

	std::string csize;
	std::getline(ist, csize);
	try{
	for (int i = 0; i < std::stoi(csize); i++){
		try{
		customers.push_back(Customer(ist));
		}catch(std::exception& e){}
	}
	}catch(std::exception& e){}
	
	std::string osize;
	std::getline(ist, osize);
	try{
	for (int i = 0; i < std::stoi(osize); i++){
		try{
		options.push_back(new Ram{ist});
		}catch(std::exception& e){}
	}
	}catch(std::exception& e){}
	
	std::string dsize;
	std::getline(ist, dsize);
	try{
	for (int i = 0; i < std::stoi(dsize); i++){
		try{
		desktops.push_back(Desktop(ist));
		}catch(std::exception& e){}
	}
	}catch(std::exception& e){}
	
	std::string ordsize;
	std::getline(ist, ordsize);
	try{
	for (int i = 0; i < std::stoi(ordsize); i++){
		try{
		orders.push_back(Order(ist));
		}catch(std::exception& e){}
	}
	}catch(std::exception& e){}

}

void Store::save(std::ostream& ost){
	ost << customers.size() << std::endl;
	for (auto c : customers){
		c.save(ost);
	}
	
	ost << options.size() << std::endl;
	for (auto o : options){
		o->save(ost);
	}
	
	ost << desktops.size() << std::endl;
	for (auto d : desktops){
		d.save(ost);
	}
	
	ost << orders.size() << std::endl;
	for (auto ord : orders){
		ord.save(ost);
	}
}
