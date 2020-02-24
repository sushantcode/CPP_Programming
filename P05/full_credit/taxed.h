#include <iostream>
#include <string>

class Taxed{
	public:
		Taxed(std::string name, double cost);
		virtual ~Taxed();
		static double set_tax_rate(double sales_tax);
		override double const price();
	private:
		static double _tax;
}
