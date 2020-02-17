#include <coin.h>

Coin::Coin(Coin_size size, Year year)
	: _size{size}, _year{year}, _notes{std::string* notes} {
	Logger::LOG("Coin::Coin");
}

Coin::Coin(const Coin& rhs)
	: _size{rhs._size}, _year{rhs._year}, _notes{new std::string{*(rhs._notes)}{
	Logger::LOG("Coin::Coin copy constructor")
}


