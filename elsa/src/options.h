#ifndef _OPTIONS_H
#define _OPTIONS_H

#include <iostream>
#include <string>
#include <iomanip>

class Options{
	public:
		Options(std::string name, double cost);
		~Options();
		double cost();
		virtual std::string to_string() const;
		virtual std::ostream& to_print(std::ostream& ost) const;
		friend std::ostream& operator<<(std::ostream& ost, const Options& option);
		Options(std::istream& ist);
		virtual void save(std::ostream& ost);
		
	protected:
		std::string _name;
		double _cost;
};
#endif
