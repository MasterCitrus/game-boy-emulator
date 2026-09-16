#pragma once

#include "cart_type.h"

#include <stdint.h>

const int MAX_CART_SIZE = 1024 * 1024;

struct CartHeader
{
	uint8_t entry_point[4];
	uint8_t nintendo_logo[48];
	uint8_t title[15];
	uint8_t cgb_flag;
	uint8_t new_licensee_code[2];
	uint8_t sgb_flag;
	uint8_t cartridge_type;
	uint8_t rom_size;
	uint8_t ram_size;
	uint8_t destination_code;
	uint8_t old_licensee_code;
	uint8_t mask_rom_version_number;
	uint8_t header_checksum;
	uint8_t global_checksum_hi;
	uint8_t global_checksum_low;
};

class Cart
{
public:

	bool load_cart(const char* file);

	void print_cart_info();

	void print_cart_data(uint16_t start_address, uint16_t end_address);

	CartHeader* get_header() const;

	uint8_t get(uint16_t address);

private:
	CartHeader* header;
	uint8_t cart_data[MAX_CART_SIZE];
};