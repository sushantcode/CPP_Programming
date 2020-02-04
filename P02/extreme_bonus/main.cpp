/* Sushant Gupta 1001520302 */
/* This program prints given text and command in the representative color including magnitude in color code. */

#include "color.h"

bool less_than(Color lhs, Color rhs){
	int result = lhs.compare(&rhs);
	if(result == 0 || result == 1){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	std::vector <Color> colors{{156,48,215}, {214,155,126}, {78,148,84}};
	std::sort (colors.begin(), colors.end(), less_than);
	for(std::vector<Color>::iterator curr_color = colors.begin(); curr_color != colors.end(); ++curr_color){
		std::cout << curr_color->colorize(curr_color->to_string()) << std::endl;
	}
	return 0;
}
