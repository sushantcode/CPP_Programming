#include <iostream>
#include <string>

class Taxfree{
	public:
		Taxfree(std::string name, double cost);
		virtual ~Taxfree();
		override double const price();
}
