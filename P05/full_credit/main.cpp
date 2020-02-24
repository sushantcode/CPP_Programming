#include "product.h"
#include "taxed.h"
#include "taxfree.h"
#include <vector>

int main(){
	Taxed snicker{"Snicker", 1.99}, pen{"Pen", 2.29}, icecream{"Ice Cream", 3.99};
	Taxfree milk{"Milk", 2.99}, water{"Water", 3.89}, bread{"Bread", 2.49};
	std::vector <Product> cart;
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
	while(quantity != 0){
		std::cout << menu << std::endl;
		std::cout << "\nEnter quantity (0 to exit) and product index: " << std::endl;
		std::cin >> quantity >> index;
		switch(index){
			case 0:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					cart.push_back(snicker);
				}
				catch (exception& e) {
					std::cerr << "Invalid quantity!!" << e.what() << std::endl;
				}
				break;
				
			case 1:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					cart.push_back(pen);
				}
				catch (exception& e) {
					std::cerr << "Invalid quantity!!" << e.what() << std::endl;
				}
				break;
				
			case 2:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					cart.push_back(icecream);
				}
				catch (exception& e) {
					std::cerr << "Invalid quantity!!" << e.what() << std::endl;
				}
				break;
				
			case 3:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					cart.push_back(milk);
				}
				catch (exception& e) {
					std::cerr << "Invalid quantity!!" << e.what() << std::endl;
				}
				break;
				
			case 4:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					cart.push_back(water);
				}
				catch (exception& e) {
					std::cerr << "Invalid quantity!!" << e.what() << std::endl;
				}
				break;
				
			case 5:
				try{
					if(quantity < 0) throw std::runtime_error("Invalid quantity!!");
					cart.push_back(bread);
				}
				catch (exception& e) {
					std::cerr << "Invalid quantity!!" << e.what() << std::endl;
				}
				break;
				
			default:
				std::cerr << "Invalid product index!!" << e.what() << std::endl;
				break;
		}
		std::cout << "Current Order\n-------------------------------\n" << std::endl;
		int total_price;
		for(int i = 0; i < cart.size(); i++){
			std::cout << cart[i] << std::endl;
			total_price += cart[i].price();
		}
		std::cout << "Total price: $" << total_price << std::endl;
	}
	return 0;
}
