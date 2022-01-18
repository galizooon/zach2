/*
 * main.cpp
 *
 *  Created on: 18 окт. 2021 г.
 *      Author: Семен Беляев
 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include "GooseWindow.h"

int main(int, char**)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	GooseWindow window1;

	window1.main_loop();


	return 0;
}


