CC = gcc
CFLAGS = -g -Wall

all: lifo

lifo.o: lifo.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(DIR)/client 

lifo: lifo.o
	$(CC) $(CFLAGS) -o $@ main.c $<

clean:
	-rm -f *.o
	-rm -f lifo

.PHONY: clean all
