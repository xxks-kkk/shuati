#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
  Conventionally, if a user appends an element to the end of a vector while
  traversing the vector, all iterators for the vector become invalid.

  Warm-up: What do you think causes all of the iterators to be invalidated?

  Challenge: Below you will find:
               - A mostly-complete implementation of a vector struct 'vector'.
               - An empty vector iterator struct 'v_iter'.
               - Function headers for the small library you will design.
             The goal of this challenge is to implement 'v_iter' in such a way
             that a 'v_iter' instance (for some 'vector' '<vec>') will never be
             invalidated by call to 'append(<vec>, <n>)'.
 */

struct vector{
   int size;
   int capacity;
   int *elems;
};

struct v_iter;

void setup_vector(struct vector *v){
   v->elems = (int*)calloc(sizeof(int), 10);
   v->size = 0;
   v->capacity = 10;
}
   
void append(struct vector *v, int n);

/* i is an output parameter */
void setup_iterator(struct vector *v, struct v_iter *i);

bool has_next(struct v_iter *i);

int get_value(struct v_iter *i);

void advance_iter(struct v_iter *i);

int main() {
   struct vector v;
   setup_vector(&v);
   
   append(&v, 0);
   append(&v, 1);
   append(&v, 2);
   append(&v, 3);
   append(&v, 4);
   append(&v, 5);
   append(&v, 6);
   append(&v, 7);
   append(&v, -1);


   struct v_iter it;
   setup_iterator(&v, &it);

   for(int i = 0; i < 40 && has_next(&it); i++, advance_iter(&it)){
      if(i % 2 == 0){
         append(&v, i);
      }
      printf("%d ", get_value(&it));
   }

   printf("\n");
   
   return 0;
}
