#ifndef _OPTIONS_H
#define _OPTIONS_H

#include <iostream>
#include <string>
#include <iomanip>
#include "options.h"

class Ram : Options{
	public:
		Ram(std::string name, double cost, int gb);
		~Ram();
		std::string to_string() const override;
		Ram(std::istream& ist);
		void save(std::ostream& ost) override;
		
	protected:
		int _gb;
};
#endif
