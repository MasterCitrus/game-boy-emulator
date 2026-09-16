#pragma once

#include <stdint.h>

class Cart;

class Memory{
public:

    Memory(Cart* cart);

    uint8_t Read8(uint16_t address);

private:
    Cart* cart;
};
