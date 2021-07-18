#pragma once
#include <iostream>
#include "config.h"
#include <SDL2/SDL.h>

class Renderer
{
private:
	static bool sdlInited;
	SDL_Renderer *renderer;
	SDL_Window *window;
	void SDLError();
public:
	Renderer();
	void update();
	void clear();
	void openWindow(const char *name, uint64_t sizex, uint64_t sizey);
	void closeWindow();
	void drawWorkPixel(uint64_t x, uint64_t y, color clr, bool fill);
	void drawPixel(uint64_t x, uint64_t y, color clr);
};
