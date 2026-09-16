#include "memory.h"
#include "gameboy/cart.h"
#include "gameboy/cart_type.h"

#include <print>

Memory::Memory(Cart *cart)
{
    this->cart = cart;
}

uint8_t Memory::Read(uint16_t address)
{
    if(address >= 0x0000 && address <= 0x3FFF)
    {
        return cart->get(address);
    }

    const CartTypeInfo& cart_type = cart_type_info[cart->get_header()->cartridge_type];

    if(address >= 0x4000 && address <= 0x7FFF)
    {
        if(cart_type.type == CartType::NO_MBC)
        {
            return cart->get(address);
        }
        else if(cart_type.type == CartType::MBC1)
        {
            const uint16_t ROM_BANK_SIZE = 0x4000;
            uint8_t rom_bank = rom_bank_number > 0 ? rom_bank_number : 1;
            const uint32_t offset = ROM_BANK_SIZE * (rom_bank - 1);
            return cart->get(offset + address);
        }
    }
    if(address >= 0x8000 && address <= 0x9FFF)
    {
        return memory[address];
    }
    if(address >= 0xA000 && address <= 0xBFFF)
    {
        if(cart_type.type == CartType::NO_MBC){
            const uint16_t eram_address = address - 0xA000;
            return eram[eram_address];
        }
        else if(cart_type.type == CartType::MBC1){
            const uint16_t bank_offset = ram_bank_number * 0x2000;
            const uint16_t eram_address = (address - 0xA000) + bank_offset;
            return eram[eram_address];
        }
    }
    if(address >= 0xC000 && address <= 0xDFFF)
    {
        return memory[address];
    }
    if(address >= 0xE000 && address <= 0xFDFF)
    {
        return memory[address - 0x2000];
    }
    if(address >= 0xFE00 && address <= 0xFE9F)
    {
        return memory[address];
    }
    if(address >= 0xFEA0 && address <= 0xFEFF)
    {
        return memory[address];
    }
    if(address >= 0xFF00 && address <= 0xFF7F)
    {
        return memory[address];
    }
    if(address >= 0xFF80 && address <= 0xFFFE)
    {
        return memory[address];
    }
    if(address == 0xFFFF)
    {
        return memory[address];
    }
    return 0xFF;
}

void Memory::Write(uint16_t address, uint8_t value)
{
    const CartTypeInfo& cart_info = cart_type_info[cart->get_header()->cartridge_type];
    if(cart_info.type == CartType::MBC1)
    {
        if(address >= 0x0000 && address <= 0x1FFF)
        {
            ram_enabled = (value & 0x0F) == 0x0A;
        }
        if(address >= 0x2000 && address <= 0x3FFF)
        {
            rom_bank_number = value & 0b00011111;
            const uint32_t rom_size = 32 * (1 << cart->get_header()->rom_size);
            const uint8_t num_of_rom_banks = rom_size / 16;
            rom_bank_number = rom_bank_number %= num_of_rom_banks;
        }
        if(address >= 0x4000 && address <= 0x5FFF)
        {
            if(rom_ram_mode_select)
            {
                ram_bank_number = value & 0b00000011;
            }
            else
            {
                rom_bank_number = (rom_bank_number & 0b00011111) | ((value & 0b00000011) <<5);
            }
        }
        if(address >= 0x6000 && address <= 0x7FFF)
        {
            rom_ram_mode_select = value &  1;
        }
    }


    if(address >= 0x8000 && address <= 0x9FFF)
    {
        memory[address] = value;
    }
    if(address >= 0xA000 && address <= 0xBFFF)
    {
        if(cart_info.type == CartType::NO_MBC)
        {
            const uint16_t eram_address = address - 0xA000;
            eram[eram_address] = value;
        }
        else if(cart_info.type == CartType::MBC1)
        {
            const uint16_t RAM_BANK_SIZE = 0x2000;
            const uint16_t offset = RAM_BANK_SIZE * ram_bank_number;
            const uint16_t eram_address = offset + (address - 0xA000);
            eram[eram_address] = value;
        }
    }
    if(address >= 0xC000 && address <= 0xDFFF)
    {
        memory[address] = value;
    }
    if(address >= 0xE000 && address <= 0xFDFF)
    {
        memory[address - 0x2000] = value;
    }
    if(address >= 0xFE00 && address <= 0xFE9F)
    {
        // PPU Mode 2 or 3, writing not allowed
        memory[address] = value;
    }
    if(address >= 0xFEA0 && address <= 0xFEFF)
    {
        // Writes ignored
    }
    if(address >= 0xFF00 && address <= 0xFF7F)
    {
        if(address == 0xFF00)
        {
            // Joypad register
            memory[address] = value;
        }
        else if(address == 0xFF02 && value == 0x81)
        {
            // Serial transfer control
            memory[address] = value;
        }
        else if(address == 0xFF04)
        {
            // Divider register
            // timer_on_div_write(value);
        }
        else if(address == 0xFF05)
        {
            // Timer counter
            memory[address] = value;
        }
        else if(address == 0xFF06)
        {
            // Timer modulo
            memory[address] = value;
        }
        else if(address == 0xFF07)
        {
            // Timer control
            memory[address] = value & 0b00000111;
        }
        else if(address == 0xFF46)
        {
            // DMA transfer
            uint16_t source_address = value << 8;
            for(int i = 0; i < 160; i++)
            {
                uint8_t data = Read(source_address + i);
                Write(0xFE00 + i, data);
            }
        }
        else if(address == 0xFF0F)
        {
            // Interrupt flag
            // interupt_flag_write(value);
        }
    }
    if(address >= 0xFEA0 && address <= 0xFEFF)
    {
        memory[address] = value;
    }
    if(address == 0xFFFF)
    {
        // Interrupt enable register
        // interupt_enable_write(value);
    }
}
