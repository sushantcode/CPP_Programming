#include "customer.h"
#include "store.h"
#include "options.h"

int main(){
	//Store elsa;
	//elsa.Store::add_customer(cust);
	//elsa.Store::add_customer(cust1);
	//int num = elsa.Store::num_customers();
	Options opt1{"Premium", 2100.00}, opt2{"Generic", 850.00};
	std::cout << opt1 << std::endl;
	return 0;
}
