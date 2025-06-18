all: stack_implementation_array

stack_implementation_array: main.o stackADT_array.o
	$(CC) -o stack_implementation_array main.o stackADT_array.o

main.o: main.c stackADT_array.h
	$(CC) -c main.c

stackADT_array.o: stackADT_array.c stackADT_array.h
	$(CC) -c stackADT_array.c

clean:
	rm -f *.o stack_implementation_array
