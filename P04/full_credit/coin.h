#ifndef _COLOR_H
#define _COLOR_H

#include <iostream>
#include <string>
#include <ostream>
#include "logger.h"


typedef int Year;

enum class Coin_size{PENNY, NICKEL, DIME, QUARTER};

class Coin{
	public:
		Coin(Coin_size size, Year year);
		Coin(const Coin& rhs);
		Coin& operator=(const Coin& rhs);
		~Coin();
		void add_note(std::string s);
		friend std::ostream& operator<<(std::ostream& ost, const Coin_size& size);
    		friend std::ostream& operator<<(std::ostream& ost, const Coin& coin);
	private:
		Coin_size _size;
		Year _year;
		std::string* _notes;
};
#endif
