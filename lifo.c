#include "lifo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item* sp = NULL;
struct buffer* ms = NULL;

void lifo_init()
{
    ms = buffer_new();
}

void lifo_free()
{
    free(ms);
    ms = NULL;
}

struct buffer* push( unsigned long long ts )
{
    struct item* p = malloc( 1 * sizeof *sp );

    if( NULL == p )
    {
        fprintf(stderr, "malloc() failed\n");
        return ms;
    }

    p->timestamp = ts;
    p->next = NULL;

    if( NULL == ms )
    {
        fprintf(stderr, "Stack not initialized ?\n");
        free(p);
        return ms;
    }
    else if( NULL == ms->head )
    { 
        ms->head = p;
        return ms;
    }
    else
    {
        p->next = ms->head;
        ms->head = p;
    }

    return ms; 
}   

struct buffer* pop( )
{   
  struct item* p = NULL;
    
  if( NULL == ms )
    {
        printf("Buffer not yet initialized\n");
    }
        else if( NULL == ms->head )
    {
        printf("No element in buffer\n");
    }
    else
    {
        p = ms->head;
        ms->head = ms->head->next;
        free(p);
    }

    return ms;
}

unsigned long long popts( ) { /* same as pop() but returns the item value */

    unsigned long long ts;
    struct item* p = NULL;

    if( NULL == ms )
    {
        printf("Buffer not yet initialized\n");
    }
    else if( NULL == ms->head )
    {
        printf("No element in buffer\n");
    }
    else
    {
        p = ms->head;
        ms->head = ms->head->next;
        ts = p->timestamp;
        free(p);
    }

    return ts;

}
struct item* top( struct buffer* s)
{
    if( NULL == s )
    {
        printf("Buffer not yet initalized\n");
        return NULL;
    }
    else if( NULL == s->head )
    {
        printf("No element in buffer\n");
    }

    return s->head;
}


struct item* make_null( struct buffer* s )
{
    if( NULL == s )
    {
        printf("Buffer not initialized (cannot make null)\n");
        return NULL;
    }
    else if( NULL == s->head )
    {
        printf("Buffer already Empty\n");
    }
    else
    {
        buffer_free(s);
    }

    return s->head;
}


struct item* is_empty( struct buffer* s )
{
    if( NULL == s )
    {
        printf("Buffer not initialized\n");
        return NULL;
    }
    else if( NULL == s->head )
    {
        printf("Buffer is Empty\n");
    }
    else
    {
        printf("Buffer is not Empty\n");
    }
    return s->head;
}


struct buffer* buffer_free( struct buffer* s )
{
    if( NULL == s )
    {
        printf("Cannot free uninitialized buffer\n");
    }

    while( s->head ) {
        pop(s);
    }

    return s;
}


struct buffer* buffer_new( void )
{
    struct buffer* p = malloc(sizeof(sp));

    if( NULL == p )
    {
        fprintf(stderr, "malloc() init failed!\n");
        exit(1);
    }

    p->head = NULL;

    return p;
}


void buffer_print( )
{
    struct item* p = NULL;

    if( NULL == ms )
    {
        printf("Can not print an Empty Stack\n");
    }
    else
    {
        for( p = ms->head; p; p = p->next ) {
            buffer_print_element(p);
        }
    }
}

void buffer_print_element(const struct item* s) /* you need to adjust this for your datatype (struct item) */
{
  if( s ) printf("timestamp = %llu\n", s->timestamp);
}

