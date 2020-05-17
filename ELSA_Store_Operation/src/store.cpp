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
	options.push_back(option.copy());
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

Store::Store(std::istream& ist){
	std::string format;
	std::getline(ist, format);
	if(format != ELSA_FILE_FORMAT){
		throw std::runtime_error{"Unsupported File Format"};
	}
	std::getline(ist, format);
	if(format != ELSA_FILE_VERSION){
		throw std::runtime_error{"Unsupported File Version"};
	}
	std::string csize;
	std::getline(ist, csize);
	try{
		for (int i = 0; i < std::stoi(csize); i++){
			customers.push_back(Customer(ist));
		}
	}catch(std::exception& e){}
	if (!ist){
		throw std::runtime_error{"Customer Data Corrupted."};
	}
	
	std::string osize;
	std::getline(ist, osize);
	for (int i = 0; i < std::stoi(osize); i++){
		std::string opt;
		std::getline(ist, opt);
		if(opt == "Options"){
			options.push_back(new Options{ist});
		}
		else if (opt == "RAM"){
			std::getline(ist, opt);
			options.push_back(new Ram{ist});
		}
		else if (opt == "CPU"){
			std::getline(ist, opt);
			options.push_back(new CPU{ist});
		}
		else if (opt == "Disk"){
			std::getline(ist, opt);
			options.push_back(new Disk{ist});
		}
		else {
			throw std::runtime_error{"Options Data Corrupted."};
		}
	}
	if (!ist){
		throw std::runtime_error{"Options Data Corrupted."};
	}
	
	std::string dsize;
	std::getline(ist, dsize);
	for (int i = 0; i < std::stoi(dsize); i++){
		desktops.push_back(Desktop(ist));
	}
	if (!ist){
		throw std::runtime_error{"Desktop Data Corrupted."};
	}
	
	std::string ordsize;
	std::getline(ist, ordsize);
	for (int i = 0; i < std::stoi(ordsize); i++){
		orders.push_back(Order(ist));
	}
	if (!ist){
		throw std::runtime_error{"Order Data Corrupted."};
	}

}

void Store::save(std::ostream& ost){
	ost << ELSA_FILE_FORMAT << "\n";
	ost << ELSA_FILE_VERSION << "\n";
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
