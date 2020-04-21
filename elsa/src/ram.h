#ifndef _RAM_H
#define _RAM_H

#include <iostream>
#include <string>
#include <iomanip>
#include "options.h"

class Ram : public Options{
	public:
		Ram(std::string name, double cost, int gb);
		~Ram();
		std::string to_string() const override;
		virtual std::ostream& to_print(std::ostream& ost) const;
		Ram(std::istream& ist);
		void save(std::ostream& ost) override;
		
	protected:
		int _gb;
};
#endif
