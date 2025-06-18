# Main Makefile for the stackADT_linked module

CC = gcc

# Wall flag: Show all warnings
# g flag: Include debug symbols
CFLAGS = -Wall -g

# Final target executable we want
TARGET = stackADT_linked

OBJS = main.o stackADT_linked.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c stackADT_linked.h
	$(CC) $(CFLAGS) -c main.c

stackADT_linked.o: stackADT_linked.c stackADT_linked.h
	$(CC) $(CFLAGS) -c stackADT_linked.c

# Cleanup all the object files and the executables 
# RECOMMENDED: Before a new make
clean:
	rm -f *.o $(TARGET)
