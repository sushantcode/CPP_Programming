/* Sushant Gupta 1001520302 */
/* This program prints given text and command in the representative color. */

#include "color.h"

bool less_than(Color lhs, Color rhs){
	if(lhs >= rhs){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	Color reset;
	std::vector <Color> colors;
	std::srand(std::time(0));
	for(int i = 0; i < 64; i++){
		colors.push_back({std::rand()%256, std::rand()%256, std::rand()%256});
	}
	std::sort (colors.begin(), colors.end(), less_than);
	for(std::vector<Color>::iterator curr_color = colors.begin(); curr_color != colors.end(); ++curr_color){
		std::cout << *curr_color << curr_color->to_string() << std::endl;
	}
	return 0;
		
	//std::cout << user_input << user_input.to_string() << std::endl;
}
