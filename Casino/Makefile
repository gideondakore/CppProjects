CXX := g++
CXXFLAGS := -c -ggdb -Wall -O0 -std=c++20
BIN := Casino.o
SRC := Casino.cpp
HFILE := Casino.hpp
EXE := casino

$(EXE): $(BIN)
	@$(CXX) -o $(EXE) $(BIN)

$(BIN): $(SRC) $(HFILE)
	@$(CXX) $(CXXFLAGS) $(SRC)

clean:
	rm -f $(EXE) $(BIN)
