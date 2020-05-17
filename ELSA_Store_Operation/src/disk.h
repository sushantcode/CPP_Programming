#ifndef _DISK_H
#define _DISK_H

#include <iostream>
#include <string>
#include <iomanip>
#include "options.h"

class Disk : public Options {
	public:
		Disk(std::string name, double cost, int tb);
		~Disk();
		std::string to_string() const override;
		Disk(std::istream& ist);
		void save(std::ostream& ost) override;
		virtual Options* copy();
		
	protected:
		int _tb;
};
#endif
