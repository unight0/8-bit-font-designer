#CC - Code Compiler
#CL - Code Linker
#R_OBJ - Result Object


CC = g++
CL = g++
C_OPT =  
L_OPT = -lSDL2
C_OBJS = *.cpp
L_OBJS = *.o
R_OBJ = 8bfd

SRC_DIR = src
BIN_DIR = bin

.DEFAULT_TARGET := all

all:                                        
	$(CC) -c $(SRC_DIR)/$(C_OBJS) $(C_OPT)
	@mv $(L_OBJS) $(BIN_DIR)
	$(CL) $(BIN_DIR)/$(L_OBJS) $(L_OPT) -o $(R_OBJ)

clear: all $(R_OBJ)
	rm *.o

run: all $(R_OBJ)
	./$(R_OBJ)
