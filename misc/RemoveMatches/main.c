#include "list.h"
#include "remove_matches.h"
#include "stdio.h"
#include "string.h"
#include "assert.h"

int
main(int argc, char *argv[])
{
    int listVals[] = {1, 1, 2, 3, 3, 4, 1, 3, 5, 5, 5};
    char *correctAnswers[] = {"1->1->2->3->3->4->1->3->5->5->5",   // 0
                              "2->3->3->4->3->5->5->5",            // 1
                              "1->1->3->3->4->1->3->5->5->5",      // 2
                              "1->1->2->4->1->5->5->5",            // 3
                              "1->1->2->3->3->1->3->5->5->5",      // 4
                              "1->1->2->3->3->4->1->3",            // 5
                              "1->1->2->3->3->4->1->3->5->5->5",   // 6
                              "1->1->2->3->3->4->1->3->5->5->5"}; // 7

    int listValsLen = 11;
    char buf[128];

    for (int valToRemove = 0; valToRemove < 7; valToRemove++)
    {
        memset(buf, 0, 128);

        struct node *list = NULL;
        for (int i = 0; i < listValsLen; i++)
        {
            listAppend(&list, listVals[i]);
        }

        // call your remove matches function here passing valToRemove
        // as the value to match
        remove_matches(&list, valToRemove);

        listSprint(list, buf);
        assert(!strcmp(buf, correctAnswers[valToRemove]));
    }

    printf("remove_matches implemented successfully\n");
    return 0;
}
