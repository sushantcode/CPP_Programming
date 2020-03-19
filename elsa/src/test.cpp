#include "customer.h"
#include "store.h"
#include "options.h"

int main(){
	Store elsa;
	Options opt1{"Premium", 2100.00}, opt2{"Generic", 850.00};
	elsa.Store::add_option(opt1);
	elsa.Store::add_option(opt2);
	int num = elsa.Store::num_options();
	std::cout << elsa.Store::option(1) << std::endl;
	return 0;
}
