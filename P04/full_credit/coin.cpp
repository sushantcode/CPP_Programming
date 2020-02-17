#include <coin.h>

Coin::Coin(Coin_size size, Year year)
	: _size{size}, _year{year}, _notes{std::string* notes} {
	Logger::LOG("Coin::Coin");
}

Coin::Coin(const Coin& rhs)
	: _size{rhs._size}, _year{rhs._year}, _notes{new std::string{*(rhs._notes)}{
	Logger::LOG("Coin::Coin copy constructor")
}

Coin& Coin::operator=(const Coin& rhs){
	: _size{rhs._size}, _year{rhs._year}, _notes{new std::string{*(rhs._notes)}{
	Logger::LOG("Coin::operator=")
	return this;
}

Coin::~Coin(){
	delete _notes;
}

Coin::add-note(std::string s){
	if(!_notes){
	_notes = new std::string{s};
	}
}

std::ostream& operator<<(std::ostream& ost, Coin& coin){
	ost << coin._year << " " << coin._size << "\n" << coin->_notes;
	return ost;
}
