#include "coin.h"

int main(){
	std::string res = "a";
	int count = 0;
	std::vector <Coin> coins;
	while(std::to_string(res) != "Q"){
		std::cout << "\n\n ================================== \n   CSE1325 COINS \n ================================== \n A)dd a coin \n L)ist all coins \n D)elete a coin \n\n Q)uit \n\n ";
		std::cout << coins.size() << "coins >> ";
		std::cin >> res;
		switch(res){
			case std::to_string("A"){
				
			}
			case std::to_string("L"){

			}
			case std::to_string("D"){

			}
			case std::to_string("Q"){
				break;
			}
			default:
				std:cout << "Invalid command input! Try again.";
				break;
		}
	}
	return 0;
}
