#ifndef _COLOR_H
#define _COLOR_H

#include <iostream>
#include <string>

class Color{
	public:
		Color(int red, int green, int blue);
		~Color();
		std::string to_string();
		std::string colorize(std::string text);
		int magnitude();
		int compare(const& rhs);
	private:
		int _red, _green, _blue;
};
#endif
