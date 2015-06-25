# Crude Makefile for 'Execute 2nd' Geany microplugin

shared_object: object
	gcc execute2nd.o -o execute2nd.so -shared `pkg-config --libs geany`

object:
	gcc -c execute2nd.c -fPIC `pkg-config --cflags geany`
