###############################################################################
## -->Makefile<--
###############################################################################

###############################################################################
##
## Instructor :  Clayton Price
## Class      :  CS5201 Spring 2016
## Assignment :  Program 1
## Programmer :  Ryan Krattiger
## Date       :  25 January 2016
## Filename   :  makefile
##
###############################################################################

###############################################################################
## This makefile will build an executable for ex1 in the first assignment.
###############################################################################

default: all

all: driver

driver: brewMain.o beer.o additives.o
	@echo Compiling driver
	-@g++ -g -Wall -W -pedantic-errors brewMain.o beer.o additives.o -o driver

brewMain.o: brewMain.cpp wine.h yeast.h additives.h wine.hpp beer.h hops.h grains.h
	@echo Compiling brewMain.o
	-@g++ -c -g -Wall -W -pedantic-errors brewMain.cpp -o brewMain.o

beer.o: beer.cpp beer.h yeast.h hops.h grains.h
	@echo Compiling beer.o
	-@g++ -c -g -Wall -W -pedantic-errors beer.cpp -o beer.o

additives.o: additives.cpp additives.h
	@echo Compiling additives.o
	-@g++ -c -g -Wall -W -pedantic-errors additives.cpp -o additives.o

clean:
	-@rm -f core > /dev/null 2>&1
	-@rm -f driver > /dev/null 2>&1
	-@rm -f brewMain.o beer.o additives.o > /dev/null 2>&1