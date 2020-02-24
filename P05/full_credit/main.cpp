#include "product.h"
#include "taxed.h"
#include "taxfree.h"
#include <vector>

int main(){
	Taxed snicker{"Snicker", 1.99}, pen{"Pen", 2.29}, icecream{"Ice Cream", 3.99};
	Taxed::set_tax_rate(0.0825);
	Taxfree milk{"Milk", 2.99}, water{"Water", 3.89}, bread{"Bread", 2.49};
	std::vector <Taxed> cartTax;
	std::vector <Taxfree> cartTaxFree;
	const std::string menu = R"(
============================================
 Welcome to the Our Store
============================================
0) Snicker ($1.99)
1) Pen ($2.29)
2) Ice Cream ($3.99)
3) Milk ($2.99)
4) Water ($3.89)
5) Bread ($2.49)
	
)";

	int quantity = 1;
	int index;
	std::cout << menu << std::endl;
	std::cout << "\nEnter quantity (0 to exit) and product index: ";
	std::cin >> quantity >> index;
	while(quantity != 0){
		std::cout << menu << std::endl;
		switch(index){
			case 0:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					snicker.Product::set_quantity(quantity);
					cartTax.push_back(snicker);
				}
				catch (std::exception& e) {
					std::cerr << "Invalid quantity!!" << e.what() << std::endl;
				}
				break;
				
			case 1:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					pen.Product::set_quantity(quantity);
					cartTax.push_back(pen);
				}
				catch (std::exception& e) {
					std::cerr << "Invalid quantity!!" << e.what() << std::endl;
				}
				break;
				
			case 2:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					icecream.Product::set_quantity(quantity);
					cartTax.push_back(icecream);
				}
				catch (std::exception& e) {
					std::cerr << "Invalid quantity!!" << e.what() << std::endl;
				}
				break;
				
			case 3:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					milk.Product::set_quantity(quantity);
					cartTaxFree.push_back(milk);
				}
				catch (std::exception& e) {
					std::cerr << "Invalid quantity!!" << e.what() << std::endl;
				}
				break;
				
			case 4:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					water.Product::set_quantity(quantity);
					cartTaxFree.push_back(water);
				}
				catch (std::exception& e) {
					std::cerr << "Invalid quantity!!" << e.what() << std::endl;
				}
				break;
				
			case 5:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					bread.Product::set_quantity(quantity);
					cartTaxFree.push_back(bread);
				}
				catch (std::exception& e) {
					std::cerr << "Invalid quantity!!" << e.what() << std::endl;
				}
				break;
				
			default:
				std::cerr << "Invalid product index!!" << std::endl;
				break;
		}
		std::cout << "Current Order\n-------------------------------\n" << std::endl;
		int total_price = 0;
		for (int i = 0; i < cartTax.size(); i++){
			std::cout << cartTax[i] << std::endl;
			total_price += cartTax[i].price();
		}
		for (int j = 0; j < cartTaxFree.size(); j++){
			std::cout << cartTaxFree[j] << std::endl;
			total_price += cartTaxFree[j].price();
		}
		std::cout << "Total price: $" << total_price << std::endl;
		std::cout << "\nEnter quantity (0 to exit) and product index: ";
		std::cin >> quantity >> index;
	}
	return 0;
}
