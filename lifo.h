/*   
* A LIFO Linked-list implementation 
* The list holds microsecond timestamps of type: unsigned long long
* Note: popts() free's the top list-item and returns it's timestamp 
*/

#ifndef LIFO_H
#define LIFO_H

#include <stdio.h>
#include <stdlib.h>

struct item
{
  unsigned long long timestamp;
  struct item* next;
};
struct buffer { struct item* head; };

void lifo_init(void);
void lifo_free(void);

struct buffer* push( unsigned long long ts );
struct buffer* pop( );
unsigned long long popts( );
struct item* top( struct buffer* );
struct item* make_null( struct buffer* );
struct item* is_empty( struct buffer* );

void buffer_print( );
void buffer_print_item( const struct item* );
struct buffer* buffer_new( void );
struct buffer* buffer_free( struct buffer* );

#endif
