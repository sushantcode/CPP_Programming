#include "product.h"
#include "taxed.h"
#include "taxfree.h"

int main(){
	Taxed snicker{"Snicker", 1.99}, pen{"Pen", 2.29}, Icecream{"Ice Cream", 3.99};
	Taxfree milk{"Milk", 2.99}, water{"Water", 3.89}, bread{"Bread", 2.49};
	std::string menu = R"(
	============================================
			Welcome to the Our Store
	============================================
	0) Snicker ($1.99)
	1) Pen ($2.29)
	2) Ice Cream ($3.99)
	3) 
	)"
}
