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

std::ostream& operator<<(std::ostream& ost,const Coin_size &coin)
{
	switch(coin)
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

std::ostream& operator<<(std::ostream& ost, const Coin& coin){
	ost << coin._year << " " << coin._size << "\n" << *(coin._notes);
	return ost;
}

std::istream& operator>>(std::istream& ist, Coin_size& size){
	std::string user_input;
	char c;
	int year;
	std::string c_size;
	std::string notes;
	ist >> user_input;	
	std::stringstream(user_input) >> year >> c >> c_size >> c >> notes;
	switch(c_size){
		case "penny":
			return ist >> Coin_size::PENNY;
		case "nickel":
			return ist >> Coin_size::NICKEL;
		case "dime":
			return ist >>Coin_size::DIME;
		case "quarter":
			return ist >> Coin_size::QUARTER;
		default:
			std::cerr << "Inavlid input of coin size!";
			break;
	}
	return ist;
}

std::istream& operator>>(std::istream& ist, Coin& coin){
	std::string user_input;
	char c;
	int year;
	std::string c_size;
	ist >> user_input;
	std::stringstream(user_input) >> year >> c >> c_size >> c >> *(coin._notes);
	coin._year = year;;
	return ist;
}
