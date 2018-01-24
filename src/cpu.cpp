#include "cpu.hpp"
#include "opcode.hpp"
#include <iostream>

namespace fusion
{
template<size_t i = 0>
inline void chain_execute(CPU &cpu, uint8_t opcode)
{
	if (base_instructions[i].opcode == opcode)
	{
		base_instructions[i].function(cpu);
		cpu._regs.pc += base_instructions[i].length;
		return;
	}

	if constexpr (i < 256)
	{
		chain_execute<i + 1>(cpu, opcode);
	}
}

CPU::CPU() :
	_ram(65536)
{}

void CPU::loop()
{
	for (;;)
	{
		uint8_t opcode = _ram[_regs.pc];
		chain_execute(*this, opcode);
	}
}
}
