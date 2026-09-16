#pragma once
#include <stdint.h>
#include <array>

class CPU;

using InstructionHandler = void (CPU::*)();

struct Instruction {
    const char* disassembly;
    uint8_t operand_length;
    InstructionHandler execute;
};

extern const Instruction instructions[256];
