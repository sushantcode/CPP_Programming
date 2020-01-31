#include <iostream>
#include <string>

//using namespace std;

class Color{
	public:
		Color(int red, int green, int blue):
		_red{red}, _green{green}, _blue{blue} {
		if(red > 255 || red < 0) throw std::runtime_error{"Invalid red component!"};
		if(green > 255 || green < 0) throw std::runtime_error{"Invalid green component!"};
		if(blue > 255 || blue < 0) throw std::runtime_error{"Invalid blue component!"};
		}
		~Color();
		std::string to_string(){
			
		}
		std::string colorize(std::string text){
			
		}
		
	private:
		int _red, _green, _blue;
		
}
