#include <iostream>
#include <string>

class Product{
	public:
		Product(std::string name, double cost);
		virtual ~Product();
		set_quantity(int quantity);
		virtual double const price();
		friend std::ostream& operator<<(ostream& ost, const Product& product);
}
