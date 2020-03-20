#include "customer.h"
#include "store.h"
#include "options.h"
#include "desktop.h"

int main(){
	Store elsa;
	Options opt1{"Premium", 2100.00}, opt2{"Generic", 850.05};
	elsa.add_option(opt1);
	elsa.add_option(opt2);
	int newDesk = elsa.new_desktop();
	elsa.add_option(0, newDesk);
	elsa.add_option(1, newDesk);
	int desktopSize = elsa.num_desktop();
	std::cout << "Total desktop = " << desktopSize << std::endl;
	std::cout << "Total cost of desktop at position " << newDesk << " = ";
	std::cout << elsa.desktop(newDesk) << std::endl;
	return 0;
}
