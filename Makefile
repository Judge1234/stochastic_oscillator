CC=gcc
CFLAGS=-I
DEPS=mavg.h


mavgmake: stochastic.c mavg_interface.c mavg_main.c
	$(CC) -o mavg stochastic.c mavg_interface.c mavg_main.c
