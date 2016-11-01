SRC=$(wildcard *.cc)
EXE=$(basename $(SRC))
CXXFLAGS= -std=c++17

default: $(EXE)
