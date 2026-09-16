#pragma once
#include <stdint.h>

#define SET_FLAG_ZERO(value)			registers.f = (registers.f & ~(1UL << 7)) | ((value) << 7);
#define GET_FLAG_ZERO					((registers.f & (1UL << 7)) >> 7);
#define SET_FLAG_SUBTRACT(value)		registers.f = (registers.f & ~(1UL << 6)) | ((value) << 6);
#define GET_FLAG_SUBTRACT				((registers.f & (1UL << 6)) >> 6);
#define SET_FLAG_HALF_CARRY(value)		registers.f = (registers.f & ~(1UL << 5)) | ((value) << 5);
#define GET_FLAG_HALF_CARRY				((registers.f & (1UL << 5)) >> 5);
#define SET_FLAG_CARRY(value)			registers.f = (registers.f & ~(1UL << 4)) | ((value) << 4);
#define GET_FLAG_CARRY					((registers.f & (1UL << 4)) >> 4);

struct Registers
{
	union
	{
		struct
		{
			uint8_t f;
			uint8_t a;
		};
		uint16_t af;
	};

	union
	{
		struct
		{
			uint8_t c;
			uint8_t b;
		};
		uint16_t bc;
	};

	union
	{
		struct
		{
			uint8_t e;
			uint8_t d;
		};
		uint16_t de;
	};

	union
	{
		struct
		{
			uint8_t l;
			uint8_t h;
		};
		uint16_t hl;
	};

	union
	{
		struct
		{
			uint8_t p;
			uint8_t s;
		};
		uint16_t sp;
	};

	uint16_t pc;
};

class CPU;
class Memory;

using InstructionHandler = void (CPU::*)();

class CPU
{
public:
	CPU(Memory* mem);

	// CPU functions
	void reset();
	void fetch();
	bool execute();

	// CPU opcode functions
	void cpu_nop(); // 0x00
	void cpu_jp_nn(); // 0xC3
	void cpu_xor_a(); // 0xAF

private:

	Registers registers;
	Memory* mem;
	uint8_t current_opcode = 0;
	InstructionHandler current_instruction_execute = nullptr;
};