CXX=g++
CFLAGS= -std=c++11
CWARN= -Wall -g -W -Wpendantic

SRC=${wildcard *.cpp}
HEADERS=${wildcard *.hpp}
OBJ=${SRC:%.cpp=%.o}

default: all

all: driver

%.o: %.cpp
	@echo "Compiling $@"
	@${CXX} ${CFLAGS} -c $< -o $@

driver: ${OBJ}
	@echo "Building $@"
	@${CXX} ${CFLAGS} ${OBJ} -o $@
	@echo ""
	@echo "Compilation success"
	@echo""

clean:
	-@rm -f core
	-@rm -f driver
	-@rm -f depend
	-@rm -f ${OBJ}

depend: ${SRC} ${HEADERS}
	@echo "Generating dependencies"
	@${CXX} -MM *.cpp > $@


-include depend

