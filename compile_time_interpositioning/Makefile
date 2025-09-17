CC = gcc
CFLAGS = -Wall -I. -DCOMPILETIME

intc: int.c mymalloc.o
	$(CC) $(CFLAGS) -o intc int.c mymalloc.o

mymalloc.o: mymalloc.c
	$(CC) $(CFLAGS) -c mymalloc.c

clean:
	rm -f *.o *.out *.a *.so intc
