#pragma once

#include <stdint.h>

class Cart;

const uint32_t MEMORY_SIZE = 64 * 1024; // 64KB
const uint32_t ERAM_SIZE = 8 * 4 * 1024;

class Memory{
public:

    Memory(Cart* cart);

    uint8_t Read(uint16_t address);
    void Write(uint16_t address, uint8_t value);

private:
    Cart* cart;
    uint16_t rom_bank_number = 0;
    uint16_t ram_bank_number = 0;
    uint8_t memory[MEMORY_SIZE];
    uint8_t eram[ERAM_SIZE];
    bool ram_enabled = false;
    bool rom_ram_mode_select = false;
};
