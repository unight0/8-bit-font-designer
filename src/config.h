#pragma once
#include <cstdint>

struct color
{
	uint8_t r, g, b, a;
};
struct coord
{
	uint64_t x, y;
};
const uint8_t workPixelSize = 64;
const char windowName[] = "8-BIT FONT DESIGNER";
const uint64_t windowSizeX = workPixelSize * (8);
const uint64_t windowSizeY = workPixelSize * (8);
const color bgClr = {0, 0, 0, 255};
