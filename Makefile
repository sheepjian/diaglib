CC=g++
CFLAGS = -g -Wall
TARGET = test

all: $(TARGET)

$(TARGET): mat.h mat.cpp vec.h main.cpp 
	$(CC) $(CFLAGS) main.cpp -o $(TARGET) 
clean:
	rm -rf *o $(TARGET)


