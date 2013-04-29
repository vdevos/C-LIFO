C-LIFO 
======

A Last In First Out buffer implemented as a Linked List in C.

I used this buffer for measuring runtimes in nested functions (see example) for logging

## Usage

In main.c the FIFO is used for calculating (nested) process runtimes in microseconds. The main idea is that you keep 
track of your process' `start time` and `push` this onto the buffer when your function ends you can `pop` it off again 
and calculate the difference: `current-time` - `start-time`

The nice thing is you won't have to keep track of timestamps withing each function and it also 
works nested/recursive (as long as you push and pop consequently!)

__TIP__ You can adjust the `struct item` in `lifo.h` for other data types (char* or other structs)

## Compiling 

Makefile    
    
    make all
    
Manual
    
    gcc -g -Wall -o lifo.o -c lifo.c
    gcc -g -Wall -o lifo main.c lifo.o  
    
## Example

see [main.c](https://github.com/vdevos/C-LIFO/blob/master/main.c)

    
