#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
/*
    vercmp compares two software version strings and returns the following:
        if v1 > v2 : return 1
        if v1 == v2 : return 0
        if v1 < v2 : return -1
    input strings are in the form "1.0.3", "2.10", "6.0.0.3", etc...
    "1.0" is considered bigger than "1" and "1.10" is greater than "1.2"
*/
int vercmp( char * v1, char * v2 ) {
    int i = 0;
    int j = 0;
    int num1 = 0;
    int num2 = 0;
    int version1ReachEnd = 0;
    int version2ReachEnd = 0;
    while (!version1ReachEnd || !version2ReachEnd)
    {
        while(version1ReachEnd == 0 && v1[i] != '.')
        {
            num1 = num1*10 + (v1[i] - '0');
            i++;
            if (v1[i] == '\0')
            {
                version1ReachEnd = 1;
            }
        }
        while(version2ReachEnd == 0 && v2[j] != '.')
        {
            num2 = num2*10 + (v2[j] - '0');
            j++;
            if (v2[j] == '\0')
            {
                version2ReachEnd = 1;
            }
        }
        if (num1 > num2 || i > j)
        {
            return 1;
        }
        else if (num2 > num1 || j > i)
        {
            return -1;
        }
        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }
    return 0;
}

int main() {
    assert( vercmp( "1.1", "1.0" ) == 1 );
    assert( vercmp( "1.0", "1.1" ) == -1 );
    assert( vercmp( "1.0", "1.0" ) == 0 );
    assert( vercmp( "1", "1.0" ) == -1 );
    assert( vercmp( "1.0", "1" ) == 1 );
    return 0;
}

