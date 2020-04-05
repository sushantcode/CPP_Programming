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
		std::string to_string() const;
		friend std::ostream& operator<<(std::ostream& ost, const Options& option);
		Options(std::istream& ist);
		void save(std::ostream& ost);
		
	private:
		std::string _name;
		double _cost;
};
#endif
