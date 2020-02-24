#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <iostream>
#include <string>

class Product{
	public:
		Product(std::string name, double cost);
		virtual ~Product();
		void set_quantity(int quantity);
		virtual double const price();
		friend std::ostream& operator<<(std::ostream& ost, const Product& product);
	protected:
		int _quantity;
		double _cost;
		std::string _name;
};
#endif
