#include "renderer.h"

bool Renderer::sdlInited = false;
void Renderer::
SDLError()
{
	std::string error = SDL_GetError();
	if(error == ""){
		error = "NO INFORMATION";
	}
	std::cout
		<<"*-------------------------------*\n"
		<<"FAILED TO INITIALIZATE SDL2\n"
		<<"MORE: "
		<<error<<"\n"
		<<"*-------------------------------*\n";

}
Renderer::
Renderer()
{
	if(!sdlInited){
		if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
			SDLError();
			exit(-1);
		}
		sdlInited = true;
	}
}
void Renderer::
openWindow(const char *name, uint64_t sizex, uint64_t sizey)
{
	window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sizex, sizey, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);

	if(!window){
		SDLError();
		exit(-1);
	}
}
void Renderer::
closeWindow()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
void Renderer::
drawWorkPixel(uint64_t x, uint64_t y, color clr, bool fill)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.h = workPixelSize;
	rect.w = workPixelSize;

	SDL_SetRenderDrawColor(renderer, clr.r, clr.g, clr.b, clr.a);
	if(fill)
		SDL_RenderFillRect(renderer, &rect);
	SDL_RenderDrawRect(renderer, &rect);
}
void Renderer::
drawPixel(uint64_t x, uint64_t y, color clr)
{
	SDL_SetRenderDrawColor(renderer, clr.r, clr.g, clr.b, clr.a);
	SDL_RenderDrawPoint(renderer, x, y);
}
void Renderer::
update()
{
	//SDL_SetRenderDrawColor(renderer, bgClr.r, bgClr.g, bgClr.b, bgClr.a);
	//SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}
void Renderer::
clear()
{
	SDL_SetRenderDrawColor(renderer, bgClr.r, bgClr.g, bgClr.b, bgClr.a);
	SDL_RenderClear(renderer);
}
