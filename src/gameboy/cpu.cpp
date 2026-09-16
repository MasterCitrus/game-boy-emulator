#include "cpu.h"
#include "cart.h"
#include "instructions.h"
#include "memory.h"
#include "emulator.h"

#include <print>

CPU::CPU(Memory *mem)
{
    this->mem = mem;
}

void CPU::reset()
{
    // DMG defaults
    registers.af = 0x01B0;
    registers.bc = 0x0013;
    registers.de = 0x00D8;
    registers.hl = 0x014D;
    registers.sp = 0x0FFFE;
    registers.pc = 0x0100;
}

void CPU::fetch()
{
    const uint16_t address = registers.pc;
    current_opcode = mem->Read(registers.pc++);
    const Instruction& instruction = instructions[current_opcode];
    current_instruction_execute = instruction.execute;
}

bool CPU::execute()
{
    if(!current_instruction_execute){
        const Instruction& instruction = instructions[current_opcode];
        const uint8_t pchi = ((registers.pc - 1) & 0xFF00) >> 8;
        const uint8_t pclo = ((registers.pc - 1) & 0xFF);

        std::println("Unknown instruction {:02X} at: 0x{:02X}{:02X} {}", current_opcode, pchi, pclo, instruction.disassembly);
        return false;
    }

    (this->*current_instruction_execute)();
    return true;
}

void CPU::cpu_nop()
{
    Emulator::increment_cpu_clock_counter(4);
}

void CPU::cpu_jp_nn()
{
    Emulator::increment_cpu_clock_counter(4);
    uint32_t temp = mem->Read(registers.pc++);
    registers.pc &= 0xFFFF;
    Emulator::increment_cpu_clock_counter(4);
    temp |= ((uint32_t)mem->Read(registers.pc++) << 8);
    registers.pc &= 0xFFFF;
    Emulator::increment_cpu_clock_counter(4);
    registers.pc = temp;
    Emulator::increment_cpu_clock_counter(4);
}

void CPU::cpu_xor_a()
{
    registers.a = 0;
    SET_FLAG_SUBTRACT(0);
    SET_FLAG_HALF_CARRY(0);
    SET_FLAG_CARRY(0);
    SET_FLAG_ZERO(1);
    Emulator::increment_cpu_clock_counter(4);
}
