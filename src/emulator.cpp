#include "emulator.h"
#include "gameboy/cpu.h"
#include "gameboy/memory.h"
#include "gameboy/cart.h"

#include <SDL3/SDL.h>
#include <iostream>

uint32_t Emulator::cpu_clock_counter = 0;

bool Emulator::initialise()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        return false;
    }

    if (!SDL_CreateWindowAndRenderer("Game Boy Emulator", 800, 600, SDL_WINDOW_RESIZABLE, &window, &renderer))
    {
        SDL_Quit();
        return false;
    }

    device.cart = new Cart();
    device.memory = new Memory(device.cart);
    device.cpu = new CPU(device.memory);

    device.cpu->reset();

    running = true;

    return true;

}

void Emulator::deinitialise()
{
    delete device.cart;
    delete device.memory;
    delete device.cpu;

    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
    }

    if (window)
    {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
}

void Emulator::run()
{
    // Startup
    if (!initialise())
    {
        return;
    }

    if(device.cart->load_cart("Tetris.gb"))
    {
        device.cart->print_cart_info();
        //device.cart->print_cart_data(0x100, 0x150);
    }
    else
    {
        std::cout << "Failed to load cartridge\n";
        running = false;
    }

    // Main loop

    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }
        }

        device.cpu->fetch();
        if(!device.cpu->execute())
        {
            running = false;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    // Shutdown
    deinitialise();
}
