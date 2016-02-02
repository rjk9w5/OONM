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
## This makefile will build an executable for ex2 in the first assignment.
###############################################################################

###############################################################################
## Generic GNU g++ compiler flags
###############################################################################
CXX = /usr/bin/g++
CXXFLAGS = -g -Wall -W -pedantic-errors
INCLUDE = -I./include
###############################################################################
## Macros for long Dependency chains in headers
###############################################################################
SIGNAL = signal.h
TOKEN = token.h enTokens.h
TOKENLIST = tokenlist.h ${TOKEN}
SCANNER = scanner.h enChar.h 
AMAT = Amatrix.h Avector.h signal.h
PARSER = parser.h ${AMAT}

OBJECTS =  driver.o\
           scanner.o\
           parser.o\
           signal.o\
           token.o\
           tokenlist.o

###############################################################################
## Relevent suffix
###############################################################################
.SUFFIXES: .cpp

###############################################################################
## Rule for compiling .cpp -> .o (used to compile lines 62-67)
###############################################################################
.cpp.o: $<
	@echo Compiling $@
	-@${CXX} -c ${CXXFLAGS} $< -o $@

###############################################################################
## Used when `make` is typed in command line. Applies target `all`
###############################################################################
default: all

###############################################################################
## Used when `make all` is typed in command line. Applies target `driver`
###############################################################################
all: driver

###############################################################################
## Used when `make driver` is typed in command line.
###############################################################################
driver: ${OBJECTS}
	@echo Compiling $@  
	-@${CXX} ${CXXFLAGS} ${OBJECTS} -o $@
	@echo Compilation Complete

###############################################################################
## Used to remove the core, `driver` executable, and all compiled objects
###############################################################################
clean:
	-@rm -f core > /dev/null 2>&1
	-@rm -f driver > /dev/null 2>&1
	-@rm -f ${OBJECTS} > /dev/null 2>&1

###############################################################################
## Dependency lists for the various source files
## This should use the .cpp.o definition to generate the
## appropriate .o files from the relevent .cpp files below
###############################################################################
driver.o: ${SIGNAL}  ${PARSER} ${SCANNER} ${TOKENLIST} driver.cpp
scanner.o: ${SCANNER} ${TOKENLIST} ${SIGNAL} scanner.cpp
parser.o: ${PARSER} ${TOKENLIST} parser.cpp
signal.o: ${SIGNAL} signal.cpp
token.o: ${TOKEN} token.cpp
tokenlist.o: ${TOKENLIST} ${SIGNAL} tokenlist.cpp