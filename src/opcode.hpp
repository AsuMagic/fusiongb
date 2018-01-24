#ifndef OPCODES_HPP
#define OPCODES_HPP

#include <functional>
#include <iostream>
#include <cstdint>
#include <array>
#include "cpu.hpp"

namespace fusion
{
struct CycleCount
{
	// Duration in clocks for non-conditional instructions or duration in clocks for conditional
	// instructions when the branch HAS been taken.
	unsigned short count;

	// Duration in clocks for conditional instructions when the branch has NOT been taken.
	// When 0, the instruction is not conditional.
	unsigned short count_not_taken = 0;
};

struct AffectedFlags
{
	bool z = 0, n = 0, h = 0, c = 0;
};

inline void nop(CPU&) {}

struct Instruction
{
	// Opcode for the instruction.
	// For CB-prefixed instructions, this is the opcode for the prefixed instruction.
	uint8_t opcode;

	void (*function)(CPU&);

	// Mnemonic of the instruction, for debugging purposes.
	// For CB-prefixed instructions
	const char *mnemonic;

	// Length in bytes of the instruction.
	// For CB-prefixed instructions this is the length of the prefixed instruction alone.
	unsigned short length;

	// Duration in cycles, see CycleCount.
	CycleCount cycles;

	// Flags that may be set by the instruction.
	AffectedFlags affected_flags = {};

	// Whether the instruction is a CB-prefixed (0xCB) instruction or not.
	bool cb_prefixed = false;
};

namespace op
{
	inline void nop(CPU& cpu) { std::cout << cpu._regs.pc << '\n'; }
}

// Handwritten with love and masochism
constexpr std::array<Instruction, 256> base_instructions
{{
//   op    handler                   mnmeonic        len   cycles    z  n  h  c   cb
//  {0x00,                           "fatname4format", 1, {12, 16}, {1, 1, 1, 1}, true}
	{0x00, op::nop,          "nop",            1, {4} }/*,
	{0x01, "ld BC,d16",      3, {12} },
	{0x02, "ld (BC),a",      1, {8} },
	{0x03, "inc BC",         1, {8} },
	{0x04, "inc B",          1, {4},      {1, 1, 1, 0} },
	{0x05, "dec B",          1, {4},      {1, 1, 1, 0} },
	{0x06, "ld B,d8",        2, {8} },
	{0x07, "rlca",           1, {4},      {1, 1, 1, 1} },
	{0x08, "ld (a16),SP",    3, {20} },
	{0x09, "add HL,BC",      1, {8},      {0, 1, 1, 1} },
	{0x0A, "ld a,(BC)",      1, {8} },
	{0x0B, "dec BC",         1, {8} },
	{0x0C, "inc C",          1, {4},      {1, 1, 1, 0} },
	{0x0D, "dec C",          1, {4},      {1, 1, 1, 0} },
	{0x0E, "ld C,d8",        2, {8} },
	{0x0F, "rrca",           1, {4},      {1, 1, 1, 1} },

	{0x10, "stop",           1, {4} }, // TODO: verify behavior, cycle count and instruction length for stop
	{0x11, "ld DE,d16",      3, {12} },
	{0x12, "ld (DE),a",      1, {8} },
	{0x13, "inc DE",         1, {8} },
	{0x14, "inc D",          1, {4},      {1, 1, 1, 0} },
	{0x15, "dec D",          1, {4},      {1, 1, 1, 0} },
	{0x16, "ld D,d8",        2, {8} },
	{0x17, "rla",            1, {4},      {1, 1, 1, 1} },
	{0x18, "jr r8",          2, {12} },
	{0x19, "add HL,DE",      1, {8},      {0, 1, 1, 1} },
	{0x1A, "ld A,(DE)",      1, {8} },
	{0x1B, "dec DE",         1, {8} },
	{0x1C, "inc E",          1, {4},      {1, 1, 1, 0} },
	{0x1D, "dec E",          1, {4},      {1, 1, 1, 0} },
	{0x1E, "ld E,d8",        2, {8} },
	{0x1F, "rra",            1, {4},      {1, 1, 1, 1} },

	{0x20, "jr NZ,r8",       2, {12, 8} },
	{0x21, "ld HL,d16",      3, {12} },
	{0x22, "ld (HL+),A",     1, {8} },
	{0x23, "inc HL",         1, {8} },
	{0x24, "inc H",          1, {4},      {1, 1, 1, 0} },
	{0x25, "dec H",          1, {4},      {1, 1, 1, 0} }*/
}};
}

#endif // OPCODES_HPP
