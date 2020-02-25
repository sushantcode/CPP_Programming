#include "product.h"
#include "taxed.h"
#include "taxfree.h"
#include <sstream>


int main(){
	Taxed snicker{"Snicker", 1.99};
	std::stringstream ss;
	ss << snicker;
	std::string result1;
	std::string result2;
	std::string result;
	ss >> result1 >> result2;
	result = result1 + result2;
	std::string testresult;
	if (result != "Snicker($1.99)"){
		testresult = "FAIL";
	}
	std::string name;
	double cost;
	double tax;
	snicker.tester(&name, &cost, &tax);
	std::cout << name << std::endl;
	return 0;
	
}

