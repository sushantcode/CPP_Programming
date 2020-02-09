#ifndef _COLOR_H
#define _COLOR_H

#include <iostream>
#include <string>
#include <sstream>

class Color{
	public:
		Color(int red, int green, int blue);
		Color();
		std::string to_string();
		int Color::magnitude()
		friend std::ostream& operator<<(std::ostream& ost, Color& color);
    	friend std::istream& operator>>(std::istream& ist, Color& color);
	private:
		int _red, _green, _blue;
		bool _reset;
		int Color::compare(const Color *rhs)
};
#endif
