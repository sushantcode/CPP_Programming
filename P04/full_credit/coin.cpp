#include "coin.h"

Coin::Coin(Coin_size size, Year year)
	: _size{size}, _year{year}, _notes{nullptr} {
	LOG("Coin::Coin");
}

Coin::Coin(const Coin& rhs)
	: _size{rhs._size}, _year{rhs._year}, _notes{new std::string{*(rhs._notes)}}{
	LOG("Coin::Coin copy constructor");
}

Coin& Coin::operator=(const Coin& rhs){
	_size = rhs._size; 
	_year = rhs._year;
	_notes = new std::string{*(rhs._notes)};
	LOG("Coin::operator=");
	return *this;
}

Coin::~Coin(){
	delete _notes;
	LOG("Coin::~Coin");
}

void Coin::add_note(std::string s){
	if(!_notes){
		_notes = new std::string{s};
	}
	else{
		*_notes = *_notes + s;
	}
}

std::ostream& operator<<(std::ostream& ost,const Coin_size& size)
{
	switch(size)
	{
		case Coin_size::PENNY:
			return ost << "penny";
		case Coin_size::NICKEL:
			return ost << "nickel";
		case Coin_size::DIME:
			return ost << "dime";
		case Coin_size::QUARTER:
			return ost << "quarter";
		default:
			throw std::runtime_error{"Coin value not available yet!"};
	}
	return ost;
}

std::ostream& operator<<(std::ostream& ost, Coin& coin){
	ost << coin._year << " " << coin._size << "\n" << *(coin._notes);
	return ost;
}
