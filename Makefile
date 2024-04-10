G++ = g++
FILES = main.cpp
EXE = Franklist
DEL = rm

all:
	$(G++) $(FILES) -o $(EXE)
del:
	$(DEL) $(EXE)