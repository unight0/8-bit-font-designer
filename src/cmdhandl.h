#pragma once
#include "config.h"
#include "fontedit.h"
#include <iostream>

class CommandHandler
{
private:
	FontEditor *fontedit;
public:
	CommandHandler(FontEditor *fontedit);
	void handle(std::string command);
};
