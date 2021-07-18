#include "cmdhandl.h"

CommandHandler::
CommandHandler(FontEditor *fontedit)
{
	this->fontedit = fontedit;
}

void CommandHandler::
handle(std::string command)
{
	if(command == "")return;
	uint8_t symbNum = 0;
	switch(command.c_str()[0])
	{
		case 'c':
			command.erase(command.begin());
			if(sscanf(command.c_str(), "%hhu", &symbNum) <= 0){
				std::cout<<"CANNOT READ SYMBOL NUMBER\n";
				break;
			}
			fontedit->setSymbNum(symbNum);
		break;
		case 's':
			command.erase(command.begin());
			fontedit->save(command);
		break;
		case 'o':
			command.erase(command.begin());
			fontedit->load(command);
		break;
		case 'i':
			command.erase(command.begin());
			if(sscanf(command.c_str(), "%hhu", &symbNum) <= 0){
				std::cout<<"CANNOT READ FONT SIZE\n";
				break;
			}
			fontedit->changeSize(symbNum);
		break;
		case 'q':
			command.erase(command.begin());
			if(sscanf(command.c_str(), "%hhu", &symbNum) <= 0){
				std::cout<<"CANNOT READ EXIT VALUE\n";
				break;
			}
			fontedit->getRenderer()->closeWindow();
			SDL_Quit();
			exit(symbNum);
		break;
		default: break;
	}
}
