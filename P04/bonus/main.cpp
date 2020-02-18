#include "coin.h"

int main(){
	char res = '0';
	int count = 0;
	std::vector <Coin> coins;
	while(res != 'Q' || res != 'q'){
		std::cout << "\n\n ================================== \n   CSE1325 COINS \n ================================== \n A)dd a coin \n L)ist all coins \n D)elete a coin \n\n Q)uit \n\n ";
		std::cout << coins.size() << " coins >> ";
		std::cin >> res;
		switch(res){
			case 'A':
				std::cout << "\n Coin (year size \\n notes): " << std::endl;
				std::cin >> &coins[count];
				break;

			case 'L':
				std::cout << "\n\n oooooooooooooooooooooooo \n    COINS   \n oooooooooooooooooooooooo \n\n";
				for(int i = 0; i < count; i++){
					std::cout << i << ")" << coins[i] << "\n\n";
				}
				break;
			
			case 'D':
				int pos;
				std::cout << "\nEnter the index to be deleted: ";
				std::cin << pos;
				coins.erase(coins.begin() + pos);
				break;
			
			case 'Q':
				exit(1);

			default:
				std::cout << "Invalid command input! Try again.";
				break;
		}
	}
	return 0;
}
