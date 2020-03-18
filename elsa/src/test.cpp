#include "customer.h"
#include "store.h"

int main(){
	Store elsa;
	Customer cust{"Sushant Gupta", "4694728021", "sushant.gupta@mavs.uta.edu"}, cust1{"Prof. Rice", "469*******", "george.rice@uta.edu"};
	elsa.Store::add_customer(cust);
	elsa.Store::add_customer(cust1);
	int num = elsa.Store::num_customers();
	Customer result = elsa.Store::customer(1);
	std::cout << result << "\n num = " << num << std::endl;
	return 0;
}
