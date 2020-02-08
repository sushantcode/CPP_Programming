#ifndef _COLOR_H
#define _COLOR_H

#include <iostream>
#include <string>

class Color{
	public:
		Color(int red, int green, int blue);
		Color();
		std::string to_string();
		friend std::ostream& operator<<(std::ostream& ost, Color& color);
    	friend std::istream& operator>>(std::istream& ist, Color& color);
	private:
		int _red, _green, _blue;
		bool _reset;
};
#endif
