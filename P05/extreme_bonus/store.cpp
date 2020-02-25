#include "product.h"
#include "taxed.h"
#include "taxfree.h"
#include <vector>

int main(){
	Taxed snicker{"Snicker", 1.99}, pen{"Pen", 2.29}, icecream{"Ice Cream", 3.99};
	Taxed::set_tax_rate(0.0825);
	Taxfree milk{"Milk", 2.99}, water{"Water", 3.89}, bread{"Bread", 2.49};
	std::vector <Product*> store = {&snicker, &pen, &icecream, &milk, &water, &bread};
	std::vector <Product*> cart;
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
	double total_price = 0;
	std::cout << menu << std::endl;
	std::cout << "Enter quantity (0 to exit) and product index (or any number preceded by 0 to checkout): ";
	std::cin >> quantity;
	while(quantity != 0){
		std::cin >> index;
		std::cout << menu << std::endl;
		switch(index){
			case 0:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					store[0]->Product::set_quantity(quantity);
					cart.push_back(store[0]->clone());
					total_price += store[0]->price();
				}
				catch (std::exception& e) {
					std::cerr << e.what() << std::endl;
				}
				break;
				
			case 1:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					store[1]->Product::set_quantity(quantity);
					cart.push_back(store[1]->clone());
					total_price += store[1]->price();
				}
				catch (std::exception& e) {
					std::cerr << e.what() << std::endl;
				}
				break;
				
			case 2:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					store[2]->Product::set_quantity(quantity);
					cart.push_back(store[2]->clone());
					total_price += store[2]->price();
				}
				catch (std::exception& e) {
					std::cerr << e.what() << std::endl;
				}
				break;
				
			case 3:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					store[3]->Product::set_quantity(quantity);
					cart.push_back(store[3]->clone());
					total_price += store[3]->price();
				}
				catch (std::exception& e) {
					std::cerr << e.what() << std::endl;
				}
				break;
				
			case 4:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					store[4]->Product::set_quantity(quantity);
					cart.push_back(store[4]->clone());
					total_price += store[4]->price();
				}
				catch (std::exception& e) {
					std::cerr << e.what() << std::endl;
				}
				break;
				
			case 5:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					store[5]->Product::set_quantity(quantity);
					cart.push_back(store[5]->clone());
					total_price += store[5]->price();
				}
				catch (std::exception& e) {
					std::cerr << e.what() << std::endl;
				}
				break;
				
			default:
				std::cerr << "Invalid product index!!" << std::endl;
				break;
		}
		std::cout << "Current Order\n--------------------------------------" << std::endl;
		std::cout << std::fixed;
		std::cout << std::setprecision(2);
		for (int i = 0; i < cart.size(); i++){
			std::cout << *cart[i] << std::endl;
		}
		std::cout << "\nTotal price: $" << total_price << std::endl;
		std::cout << "Enter quantity (0 to exit) and product index (or any number preceded by 0 to checkout): ";
		std::cin >> quantity;
	}
	return 0;
}
