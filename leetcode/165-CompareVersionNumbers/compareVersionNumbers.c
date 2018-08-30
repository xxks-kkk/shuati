#include <stdlib.h>
#include <assert.h>
#include <string.h>


int
compareVersion( char *version1, char *version2 )
{
    int i = 0;
    int j = 0;
    int num1 = 0;
    int num2 = 0;
    int version1ReachEnd = 0;
    int version2ReachEnd = 0;
    while (!version1ReachEnd || !version2ReachEnd)
    {
        while(version1ReachEnd == 0 && version1[i] != '.')
        {
            num1 = num1*10 + (version1[i] - '0');
            i++;
            if (version1[i] == '\0')
            {
                version1ReachEnd = 1;
            }
        }
        while(version2ReachEnd == 0 && version2[j] != '.')
        {
            num2 = num2*10 + (version2[j] - '0');
            j++;
            if (version2[j] == '\0')
            {
                version2ReachEnd = 1;
            }
        }
        if (num1 > num2)
        {
            return 1;
        }
        else if (num2 > num1)
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

void test()
{
    char* version1 = "0.1";
    char* version2 = "0.2";
    assert(compareVersion(version1, version2) == -1);
    version1 = "1.0.1";
    version2 = "1";
    assert(compareVersion(version1, version2) == 1);
    version1 = "7.5.2.4";
    version2 = "7.5.3";
    assert(compareVersion(version1, version2) == -1);
}


int main()
{
    test();
}
