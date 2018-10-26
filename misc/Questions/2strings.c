#include <stdio.h>

int main( int argc, char* argv[] ){
    // a pointer, initialized to point to a string constant (stored in the data segment);
    // the pointer may subsequently be modified to point elsewhere but the result is undefined if you try to
    // modify the string constants (K&R p.104)
    char* string1 = "string";

    // an array just big enough to hold the sequence of characters and '\0' that initialize it. Individual characters
    // within the array may be changed but `string2` will always refer to the same storage.
    char string2[] = "string";
}
