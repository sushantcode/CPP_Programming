#ifndef _COLOR_H
#define _COLOR_H

#include <iostream>
#include <string>

typedef int Year
enum class Coin_size{PENNY,NICKEL,DIME,QUARTER};

class Logger{
	public:
		LOG(std::string msg);
}

class Coin{
	public:
		Coin(Coin_size size, Year year);
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
