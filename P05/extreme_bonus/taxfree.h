#ifndef __TAXFREE_H
#define __TAXFREE_H

#include <iostream>
#include <string>
#include "product.h"

class Taxfree : public Product{
	public:
		Taxfree(std::string name, double cost);
		virtual ~Taxfree();
		double const price() override;
		Product* clone() override;
};
#endif
