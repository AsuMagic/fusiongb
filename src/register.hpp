#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <array>
#include <cstdint>

namespace fusion
{
using R8 = uint8_t;
using R16 = uint16_t;

struct RegisterFile
{
	static R8& low(R16 &reg)  { return reinterpret_cast<R8*>(&reg)[0]; }
	static R8& high(R16 &reg) { return reinterpret_cast<R8*>(&reg)[1]; }

	R16 af{0x01B0}, bc{0x0013}, de{0x00D8}, hl{0x014D}, sp{0xFFFE}, pc{0x0100};
	R8 &a{high(af)}, /*&f{low(af)},*/
	   &b{high(bc)}, &c{low(bc)},
	   &d{high(de)}, &e{low(de)},
	   &h{high(hl)}, &l{low(hl)};
};
}

#endif // REGISTER_HPP
