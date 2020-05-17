#ifndef __TAXED_H
#define __TAXED_H

#include <iostream>
#include <string>
#include "product.h"

class Taxed : public Product{
	public:
		Taxed(std::string name, double cost);
		virtual ~Taxed();
		static void set_tax_rate(double sales_tax);
		double const price() override;
		void tester(std::string *name, double *cost, double *tax);
	private:
		static double _tax;
};
#endif
