CC=g++
TARGET = sort-sfml
INC_DIR = ./headers
SRC_DIR = ./src
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system
HEADER = $(INC_DIR)/*.hpp

SRC_CPP = $(shell find $(SRC_DIR) -name '*.cpp')
SRC_CPP += main.cpp

OBJ = $(SRC_CPP:%=%.o)

all: $(TARGET) clean

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDLIBS)

%.cpp.o: %.cpp $(HEADER)
	$(CC) -c $< -o $@

clean:
	rm -f *.o $(SRC_DIR)/*.cpp.o
