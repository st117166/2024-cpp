CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = main

SRC = main.cpp
OBJ = main.o

$(TARGET): $(OBJ)
$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

main.o: main.cpp Array.h
$(CXX) $(CXXFLAGS) -c main.cpp

clean:
rm -f $(OBJ) $(TARGET)

rebuild: clean $(TARGET)

.PHONY: clean rebuild