#ifndef CPU_HPP
#define CPU_HPP

#include "register.hpp"
#include <vector>

namespace fusion
{
struct CPU
{
	RegisterFile _regs;
	std::vector<uint8_t> _ram;

	CPU();
	void loop();
};
}

#endif // CPU_HPP
