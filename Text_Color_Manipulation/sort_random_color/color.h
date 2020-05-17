#ifndef _COLOR_H
#define _COLOR_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>

class Color{
	public:
		Color(int red, int green, int blue);
		Color();
		std::string to_string();
		int magnitude();
		friend std::ostream& operator<<(std::ostream& ost, Color& color);
    	friend std::istream& operator>>(std::istream& ist, Color& color);
    	bool operator<(Color& rhs);
    	bool operator<=(Color& rhs);
		bool operator==(Color& rhs);
		bool operator!=(Color& rhs);
		bool operator>=(Color& rhs);
		bool operator>(Color& rhs);
	private:
		int _red, _green, _blue;
		bool _reset;
		bool compare(const Color *rhs);
};
#endif
