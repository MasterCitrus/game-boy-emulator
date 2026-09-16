#include "memory.h"
#include "gameboy/cart.h"

#include <print>

Memory::Memory(Cart *cart)
{
    this->cart = cart;
}

uint8_t Memory::Read8(uint16_t address)
{
    const uint8_t value = cart->get(address);
    std::println("Read8 address={:04X} value={:02X}", address, value);
    return value;
}