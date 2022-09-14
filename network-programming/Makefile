#Makefile

compiler=gcc

all:
	$(compiler) network_adapters.c -o network_adapters


test:
	valgrind --tool=memcheck --leak-check=full ./network_adapters
