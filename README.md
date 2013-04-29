LIFO Linked List
======

A LIFO (Last In First Out) Linked List implementation in C.

I used this buffer for nested functions and measuring their respective runtimes (see example)

You can adjust the `struct item` in `lifo.h` for data types!

## Usage

In main.c the FIFO is used for calculating (nested) process runtimes. The main idea is that you keep track 
of your process' start timestamps on a stack (push at start of function) when your function ends you can
pop it off and take the difference (this is your function runtime).

The nice thing is you won't have to keep track of timestamps withing each function and it also 
works nested/recursive (as long as you push and pop consequently!)

## Compiling 

Makefile    
    
    make all
    
Manual
    
    gcc -g -Wall -o lifo.o -c lifo.c
    gcc -g -Wall -o lifo main.c lifo.o  
    
## Example

see [main.c](https://github.com/vdevos/C-LIFO/edit/master/main.c)

    
