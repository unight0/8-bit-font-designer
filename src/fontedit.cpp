#include "fontedit.h"

FontEditor::
FontEditor(uint8_t fontSize, Renderer *renderer)
{
	this->renderer = renderer;
	font.size = fontSize;
	pos = {0, 0};
	symbolNum = 0;

	for(uint8_t *ptr = (uint8_t*)font.symbols;
			ptr < ((uint8_t*)font.symbols + font.size * sizeof(symbol8)); ptr++){
		*ptr = 0;
	}
}

void FontEditor::
moveCursor(coord pos)
{
	if(pos.x >= symbol8::xSize || pos.y >= symbol8::ySize){
		return;
	}
	this->pos = pos;
}
void FontEditor::
setSymbNum(uint8_t symbolNum)
{
	if(symbolNum > font.size - 1){
		return;
	}
	this->symbolNum = symbolNum;
}
coord FontEditor::
getCursor()
{
	return pos;
}
Renderer *FontEditor::
getRenderer()
{
	return renderer;
}
void FontEditor::
togglePixel()
{
	font.symbols[symbolNum].map[pos.x][pos.y] = !font.symbols[symbolNum].map[pos.x][pos.y];
}
void FontEditor::
update()
{
	for(uint64_t x = 0; x < symbol8::xSize; x++){
		for(uint64_t y = 0; y < symbol8::ySize; y++){
			if(font.symbols[symbolNum].map[x][y]){
				renderer->drawWorkPixel(x*workPixelSize, y*workPixelSize, {255, 255, 255, 255}, 1);
			}else{
				renderer->drawWorkPixel(x*workPixelSize, y*workPixelSize, bgClr, 1);
			}

			if(pos.x == x && pos.y == y){
				renderer->drawWorkPixel(x*workPixelSize, y*workPixelSize, {255, 0, 0, 255}, 0);
			}
		}
	}
	renderer->update();
}
void FontEditor::
save(std::string file)
{
	std::ofstream ofile;
	ofile.open(file.c_str(), std::ios::binary | std::ios::trunc);

	if(!ofile.good()){
		std::cout<<"CANNOT WRITE TO FILE:"<<file<<std::endl;
		ofile.close();
		return;
	}
	ofile.write((const char*)&font, sizeof(font8));
	ofile.close();
}
void FontEditor::
load(std::string file)
{
	std::ifstream ifile;
	ifile.open(file.c_str(), std::ios::binary);

	if(!ifile.good()){
		std::cout<<"CANNOT READ FILE:"<<file<<std::endl;
		ifile.close();
		return;
	}
	ifile.read((char*)&font, sizeof(font8));
	ifile.close();
}
void FontEditor::
changeSize(uint8_t symbNum)
{
	font.size = symbNum;
}
