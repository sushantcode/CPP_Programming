#include "desktop.h"

Desktop::Desktop(){ }

void Desktop::add_option(Options& option){
	options.push_back(&option);
}

double Desktop::price() const{
	double sum = 0;
	for (auto o : options){
		sum = sum + o->cost();
	}
	return sum;
}

std::ostream& operator<<(std::ostream& ost, const Desktop& desktop){
	std::string output;
	for (auto o : desktop.options){
		output = output + o->to_string() + "\n";
	}
	ost << "<b> <span size = '10000'>This Desktop includes: </span></b> \n" << output;
	return ost;
}

Desktop::Desktop(std::istream& ist) {
	std::string osize;
	std::getline(ist, osize);
	try{
		for (int i = 0; i < std::stoi(osize); i++){
			try{
				options.push_back(new Options(ist));
			}catch(std::exception& e){}
	}
	}catch(std::exception& e){}
}

void Desktop::save(std::ostream& ost) {
	ost << options.size() << std::endl;
	for (auto o : options){
		o->save(ost);
	}
}
