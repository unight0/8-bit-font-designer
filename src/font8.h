#pragma once
#include <cstdint>

struct symbol8
{
	static const uint8_t xSize = 8;
	static const uint8_t ySize = 8;
	bool map[xSize][ySize];
};

struct font8
{
	uint8_t size;
	symbol8 symbols[256];
};

