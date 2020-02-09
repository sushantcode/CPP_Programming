/* Sushant Gupta 1001520302 */
/* This program prints and sorts several random RGB codes in the representative color. */

#include "color.h"

int main(){
	Color reset;
	std::vector <Color> colors;
	std::srand(std::time(0));
	for(int i = 0; i < 64; i++){
		colors.push_back({std::rand()%256, std::rand()%256, std::rand()%256});
	}
	std::sort (colors.begin(), colors.end());
	for(std::vector<Color>::iterator curr_color = colors.begin(); curr_color != colors.end(); ++curr_color){
		std::cout << *curr_color << curr_color->to_string() << " " << reset << curr_color->magnitude() << std::endl;
	}
	return 0;
}
