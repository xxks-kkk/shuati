#include <stdio.h>

int main() {
  char * s = "12345";
  // what do these print?
  printf( "%d\n", s );         // 202104714  <- memory address of the pointer
  printf( "%d\n", *s );        // 49  <- ascii value of '1'
  printf( "%c\n", *s );        // 1   <- '1' as char value
  printf( "%c\n", *(s + 1) );  // 2   <- '2' as char value
  printf( "%s\n", s );         // 12345
  //printf( "%s\n", *s );      // Seg fault
}
