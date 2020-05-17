#ifndef _RAM_H
#define _RAM_H

#include <iostream>
#include <string>
#include <iomanip>
#include "options.h"

class Ram : public Options {
	public:
		Ram(std::string name, double cost, int gb);
		~Ram();
		std::string to_string() const override;
		Ram(std::istream& ist);
		void save(std::ostream& ost) override;
		virtual Options* copy();
		
	protected:
		int _gb;
};
#endif
