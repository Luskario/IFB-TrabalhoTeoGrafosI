TARGET = main
CFLAGS = -Wall
CC = g++
LDFLAGS = -lm

SRC = $(wildcard ./src/*.cpp)
OBJ = $(SRC:.cpp =.o)

main: $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp ./libs/%.h
	$(CC) $(CFLAGS) -c $<


.PHONY: clean

clean:
	rm main $(OBJ)