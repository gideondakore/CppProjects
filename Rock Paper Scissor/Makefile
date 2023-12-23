CXX:= g++
CXXFLAGS:= -c -ggdb -Wall -O0 -std=c++20
BIN:= rock_paper_scissor.o
SRC:= rock_paper_scissor.cpp

rock: $(BIN)
	@$(CXX) -o rock $(BIN)
$(BIN): $(SRC)
	@$(CXX) $(CXXFLAGS) $(SRC)
