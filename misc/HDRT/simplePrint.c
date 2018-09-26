// Hudson River Trading On-Campus 09/25/18
// Implement the function() that ables us to print "Hello World!" in the end.

#include <stdio.h>

// modify this function
void function(char** c)
{
    *c = "Hello World!";
}

int main()
{
    char* s;
    function(&s); // modify herefunction(s);
    puts(s);
    return 0;
}