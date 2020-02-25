#include "product.h"
#include "taxed.h"
#include "taxfree.h"
#include <sstream>


int main(){
	Taxed snicker{"Snicker", 1.99};
	std::string testresult;
	std::string name;
	double cost;
	double tax;
	Taxed::set_tax_rate(0.0825);
	snicker.tester(&name, &cost, &tax);
	if(name != "Snicker"){
		std::cerr << "FAIL: _name inherited attribute of Taxed instance not initialized!! " << name << std::endl;
		testresult = "FAIL";
	}
	if(cost != 1.99){
		std::cerr << "FAIL: _cost inherited attribute of Taxed instance not initialized!! " << cost << std::endl;
		testresult = "FAIL";
	}
	if(tax != 0.0825){
		std::cerr << "FAIL: _tax local attribute of Taxed instance not initialized!! " << 0.0825 << std::endl;
		testresult = "FAIL";
	}
	std::stringstream ss;
	ss << snicker;
	std::string result1;
	std::string result2;
	std::string result;
	ss >> result1 >> result2;
	result = result1 + result2;
	if (result != "Snicker($1.99)"){
		std::cerr << "FAIL:: Operator<< overload of Taxed instance is not working!!" << std::endl;
		testresult = "FAIL";
	}
	
	Taxfree milk{"Milk", 3.49};
	milk.tester(&name, &cost);
	if(name != "Milk"){
		std::cerr << "FAIL: _name inherited attribute of Taxfree instance not initialized!! " << name << std::endl;
		testresult = "FAIL";
	}
	if(cost != 3.49){
		std::cerr << "FAIL: _cost inherited attribute of Taxfree instance not initialized!! " << cost << std::endl;
		testresult = "FAIL";
	}
	std::stringstream ss1;
	ss1 << milk;
	ss1 >> result1 >> result2;
	result = result1 + result2;
	if (result != "Milk($3.49)"){
		std::cerr << "FAIL:: Operator<< overload of Taxfree instance is not working!!" << std::endl;
		testresult = "FAIL";
	}
	if (testresult == "FAIL"){
		std::cout << testresult << std::endl;
	}
	return 0;
}

