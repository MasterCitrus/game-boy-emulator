#include "cart.h"

#include <fstream>
#include <format>
#include <iostream>


bool Cart::load_cart(const char* filename)
{
    std::streampos size;
    std::ifstream file(filename, std::ios::in | std::ios::binary | std::ios::ate);
    if (!file.is_open())
    {
        return false;
    }

    size = file.tellg();
    file.seekg(0, std::ios::beg);
    file.read((char*)cart_data, MAX_CART_SIZE);
    file.close();

    header = (CartHeader*)(cart_data + 0x100);

    return true;
}

void Cart::print_cart_info()
{
    std::cout << std::format("Entry Point: {:X}{:X}{:X}{:X}\n", header->entry_point[0], header->entry_point[1], header->entry_point[2], header->entry_point[3]);
    std::cout << std::format("Title: {}\n", std::string_view(reinterpret_cast<const char*>(header->title), sizeof(header->title)));
}

void Cart::print_cart_data(uint16_t start_address, uint16_t end_address)
{
    for (uint16_t i = start_address; i < end_address; ++i)
    {
        std::cout << std::format("Address {:04X}: {:02X}\n", i, cart_data[i]);
    }
}

CartHeader *Cart::get_header() const
{
    return header;
}

uint8_t Cart::get(uint16_t address)
{
    return cart_data[address];
}
