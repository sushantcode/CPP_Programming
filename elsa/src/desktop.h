#ifndef _DESKTOP_H
#define _DESKTOP_H

#include <iostream>
#include <string>
#include <vector>
#include "options.h"

class Desktop{
	public:
		Desktop();
		void add_option(Options& option);
		double price() const;
		friend std::ostream& operator<<(std::ostream& ost, const Desktop& desktop);
		Desktop(std::istream& ist);
		void save(std::ostream& ost);
		
		
	private:
		std::vector<Options*> options;
};
#endif
