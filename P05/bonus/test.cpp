#include "product.h"
#include "taxed.h"
#include "taxfree.h"
#include <sstream>


int main(){
	Taxed snicker{"Snicker", 1.99};
	std::string name;
	double cost;
	double tax;
	Taxed::set_tax_rate(0.0825);
	snicker.tester(&name, &cost, &tax);
	if(name != "Snicker"){
		std::cerr << "FAIL: _name inherited attribute not initialized!! " << name << std::endl;
		testresult = "FAIL";
	}
	if(cost != 1.99){
		std::cerr << "FAIL: _cost inherited attribute not initialized!! " << cost << std::endl;
		testresult = "FAIL";
	}
	if(tax != 0.0825){
		std::cerr << "FAIL: _tax local attribute not initialized!! " << 0.0825 << std::endl;
		testresult = "FAIL";
	}
	std::cout << tax << std::endl;
	
	std::stringstream ss;
	ss << snicker;
	std::string result1;
	std::string result2;
	std::string result;
	ss >> result1 >> result2;
	result = result1 + result2;
	std::string testresult;
	if (result != "Snicker($1.99)"){
		std::cerr << "FAIL:: Operator<< overload is not working!!" << std::endl;
		testresult = "FAIL";
	}
	
	return 0;
	
}

