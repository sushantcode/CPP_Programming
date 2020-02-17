#ifndef _COLOR_H
#define _COLOR_H

#include <iostream>
#include <string>

enum class{PENNY,NICKEL,DIME,QUARTER};


class Coin{
	public:
		
		Coin(Size size, Year year);
		Coin(const Coin& rhs);
		Coin& operator=(const Coin& rhs);
		~Coin();
		add-note(std::string s);
		friend std::ostream& operator<<(std::ostream& ost, Coin& coin);
    		friend std::istream& operator>>(std::istream& ist, Coin& coin);
	private:
		Coin_size _size;
		Year _yera;
		std::string* _notes;
};
#endif
