#include "cpu.h"

CPU::CPU(std::string name, double cost, double frequency)
	: Options{name, cost}, _frequency{frequency} { }

CPU::~CPU() { }

std::string CPU::to_string() const{
	std::ostringstream costStream;
	std::ostringstream freqStream;
	costStream << std::fixed << std::setprecision(2) << _cost;
	freqStream << std::fixed << std::setprecision(2) << _frequency;
	return "CPU: " + freqStream.str() + " Ghz " + _name + "($" + costStream.str() + ")";
}

CPU::CPU(std::istream& ist)
	: Options(ist){
	std::string size;
	std::getline(ist, size);
	try{
		_frequency = std::stod(size);
	}catch(std::exception& e){
		throw std::runtime_error{"CPU Data Corrupted."};
	}
}

void CPU::save(std::ostream& ost){
	ost << "CPU\n";
	Options::save(ost);
	ost << _frequency << std::endl;
}

Options* CPU::copy(){
	return new CPU{*this};
}
