8-bit font designer
===================

## COMMANDS:
  Commands have two parts: command symbol(c, s, o, i, q) and argument.  
  Command are **_NOT_** separated from argument.  

###	Examples:
  c11: Command symbol - c, argument - 11.  
  i64: Command symbol - i, argument - 64.  

### Available commands:
  __c__*[symbol number]* - edit symbol  
  __s__*[file name]* - save font to file  
  __o__*[file name]* - open file  
  __i__*[size]* - change size of font. Default - 255  
  __q__*[no argument]* - exit  

## Info:
* You can toggle pixel with space.
* To move cursor you can use arrow keys.
* Commands that you type will be outputed to console.
* Symbol size is 8x8 pixels.
* Maximum symbols count is 256(0...255).
* You cannot access symbol with index > size.
* __ATTENTION: font8.h is important file. You will need it to read font from file.__  

## Installation
  You will need SDL2 and make for compiling.  
  Then run:
  
