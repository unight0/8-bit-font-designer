#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include "config.h"
#include "renderer.h"
#include "fontedit.h"
#include "font8.h"
#include "cmdhandl.h"


int main()
{
	Renderer renderer;
	FontEditor fontedit(255, &renderer);
	CommandHandler cmdhandl(&fontedit);
	renderer.openWindow(windowName, windowSizeX, windowSizeY);

	bool isAccord = false;
	std::string accord = "";
	while(true)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			int64_t key = event.key.keysym.sym;
			switch(event.type)
			{
				case SDL_QUIT: renderer.closeWindow(); SDL_Quit(); return 0;
				case SDL_KEYDOWN:
					switch(key)
					{
						case SDLK_UP: fontedit.moveCursor({fontedit.getCursor().x, fontedit.getCursor().y - 1}); break;
						case SDLK_DOWN: fontedit.moveCursor({fontedit.getCursor().x, fontedit.getCursor().y + 1}); break;
						case SDLK_LEFT: fontedit.moveCursor({fontedit.getCursor().x - 1, fontedit.getCursor().y}); break;
						case SDLK_RIGHT: fontedit.moveCursor({fontedit.getCursor().x + 1, fontedit.getCursor().y}); break;
						case SDLK_SPACE: fontedit.togglePixel(); break;
						case 13: std::cout<<'\n'; isAccord = false; cmdhandl.handle(accord); accord = ""; break;
						default:
							if(key == 'c' || key == 's' || key == 'o' || key == 'i' || key == 'q'){
								isAccord = true;
							} 
							if(isAccord && ((key >= 'a' && key <= 'z')) || (key >= 'A' && key <= 'Z')){
								std::cout<<(char)key;
								accord += key;
							}
							else if(isAccord && (key >= '0' && key <='9')){
								std::cout<<(char)key;
								accord += key;
							}
						break;
					}

				break;
			}
		}
		fontedit.update();
		SDL_Delay(1000/60);
		renderer.clear();
	}

	renderer.closeWindow();
	SDL_Quit();
}
