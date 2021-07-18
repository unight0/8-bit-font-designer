#pragma once
#include "config.h"
#include "renderer.h"
#include "font8.h"
#include <fstream>

class FontEditor
{
private:
	font8 font;
	Renderer *renderer;
	uint8_t symbolNum;
	coord pos;
public:
	FontEditor(uint8_t fontSize, Renderer *renderer);
	void moveCursor(coord pos);
	void togglePixel();
	void setSymbNum(uint8_t symbolNum);
	coord getCursor();
	void update();
	void save(std::string file);
	void load(std::string file);
	void changeSize(uint8_t symbNum);
	Renderer *getRenderer();
};
