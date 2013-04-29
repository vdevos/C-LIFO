CC = gcc
CFLAGS = -g -Wall

all: lifo
test: lifotest

lifo.o: lifo.c
    $(CC) $(CFLAGS) -o $@ -c $< -I$(DIR)/client 

lifo: lifo.o
    $(CC) $(CFLAGS) -o $@ main.c $<

lifotest: test/lifotest.c lifo.o
    $(CC) $(CFLAGS) -o test/$@ $^

clean:
    -rm -f *.o
    -rm -f /test/lifotest

.PHONY: clean all
