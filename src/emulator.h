#pragma once
#include <stdint.h>

struct SDL_Window;
struct SDL_Renderer;

class CPU;
class Memory;
class Cart;

struct Device{
	CPU* cpu = nullptr;
	Memory* memory = nullptr;
	Cart* cart = nullptr;
};

class Emulator
{
public:

	bool initialise();
	void deinitialise();

	void run();

	static void increment_cpu_clock_counter(uint32_t cycles) { cpu_clock_counter += cycles; }

private:
	static uint32_t cpu_clock_counter;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Device device;
	bool running = false;
};