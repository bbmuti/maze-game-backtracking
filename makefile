CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -Wpedantic -Iinclude

TARGET := bin/maze-game
OBJECTS := lib/Konum.o lib/Labirent.o

.PHONY: all run clean

all: $(TARGET)

bin lib:
	mkdir -p $@

lib/Konum.o: src/Konum.cpp include/Konum.hpp | lib
	$(CXX) $(CXXFLAGS) -c $< -o $@

lib/Labirent.o: src/Labirent.cpp include/Labirent.hpp include/Konum.hpp include/Stack.hpp | lib
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS) src/Test.cpp | bin
	$(CXX) $(CXXFLAGS) $(OBJECTS) src/Test.cpp -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf bin lib
