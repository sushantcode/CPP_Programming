#include "customer.h"
#include "store.h"
#include "options.h"
#include "desktop.h"

int main(){
	Store elsa;
	Options opt1{"Premium", 2100.00}, opt2{"Generic", 850.00};
	elsa.add_option(opt1);
	elsa.add_option(opt2);
	/*int newDesk = elsa.add_option
	int num = elsa.num_options();*/
	std::cout << elsa.option(1) << std::endl;
	return 0;
}
