CXX := g++
CXXFLAGS := -c -ggdb -Wall -O0 -std=c++20
BIN := cgpa.o
SRC := cgpa.cpp

grade: $(BIN)
	@$(CXX) -o grade $(BIN)

cgpa.o: $(SRC)
	@$(CXX) $(CXXFLAGS) $(SRC) 
