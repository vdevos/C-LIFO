C-LIFO 
======

A Last In First Out buffer implemented as a Linked List in C.

I used this buffer for measuring runtimes in nested functions (see [example](https://github.com/vdevos/C-LIFO/blob/master/main.c)) for logging

## Usage

In main.c the FIFO is used for calculating (nested) process runtimes in microseconds. The main idea is that you keep 
track of your process' `start time` and `push` this onto the buffer when your function ends you can `pop` it off again 
and calculate the difference: `current-time` - `start-time`

The good thing is you don't have to keep track of timestamps withing each function itself and that it also 
works for nested functions (as long as you push and pop consequently!)

__TIP__ You can adjust the `struct item` in `lifo.h` for other data types (char* or other structs)

## Compiling 

Makefile    
    
    make all
    
Manual
    
    gcc -g -Wall -o lifo.o -c lifo.c
    gcc -g -Wall -o lifo main.c lifo.o  
    
## Example

### Basic
    #include "lifo.h"
    
    int main(int argc, char** argv)
    {
        lifo_init();
    
        int i;
        for(i = 0; i < 10; i++) 
        {            
            push(i);
            pop();
        }
    
        lifo_free();
        
        return 0;
    }

### Advanced

See [main.c](https://github.com/vdevos/C-LIFO/blob/master/main.c) for a impression (the way I used it)


    
