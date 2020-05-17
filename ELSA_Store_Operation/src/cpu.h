#ifndef _CPU_H
#define _CPU_H

#include <iostream>
#include <string>
#include <iomanip>
#include "options.h"

class CPU : public Options {
	public:
		CPU(std::string name, double cost, double frequency);
		~CPU();
		std::string to_string() const override;
		CPU(std::istream& ist);
		void save(std::ostream& ost) override;
		virtual Options* copy();
		
	protected:
		double _frequency;
};
#endif
