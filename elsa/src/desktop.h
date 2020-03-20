#ifndef _DESKTOP_H
#define _DESKTOP_H

#include <iostream>
#include <string>
#include <vector>
#include "options.h"

class Desktop{
	public:
		void add_option(Options& option);
		double price() const;
		friend std::ostream& operator<<(std::ostream& ost, const Desktop& Desktop);
		
	private:
		std::vector<Options*> options;
};
#endif
