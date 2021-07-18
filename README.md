#8-bit font designer

COMMANDS:
	Commands have two parts: command symbol(c, s, o, i, q) and argument.
	Command are NOT separated from argument.
	Examples:
		c11: Command symbol - c, argument - 11.
		i64: Command symbol - i, argument - 64.

	Available commands:
		c[symbol number] - edit symbol
		s[file name] - save font to file
		o[file name] - open file
		i[size] - change size of font. Default - 255
		q[NO ARGUMENT] - exit
INFO:
	You can toggle pixel with space.
	To move in the greed you can use arrow keys.
	Commands that you type will be outputed to console.
	Symbol size is 8x8 pixels.
	Maximum symbols count is 256(0...255).
	You cannot access symbol with index > size.

	ATTENTION: font8.h is important file. You will need it to read font from file later.
	
