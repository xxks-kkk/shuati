/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <set>

#include "linkedList.h"

using namespace std;

class Solution
{
public:
    ListNode *
    getIntersectionNode( ListNode *headA, ListNode *headB )
    {
        unordered_set<ListNode *> s;
        for ( auto ptrA = headA; ptrA != nullptr; ptrA = ptrA->next )
        {
            s.insert( ptrA );
        }
        for ( auto ptrB = headB; ptrB != nullptr; ptrB = ptrB->next )
        {
            if ( s.find( ptrB ) != s.end())
            {
                return ptrB;
            }
        }
        return nullptr;
    }


    // Optimized Solution: two pointers
    ListNode *
    getIntersectionNode2( ListNode *headA, ListNode *headB )
    {
        auto ptrA = headA;
        auto ptrB = headB;
        while ( ptrA != ptrB )
        {
            // Be careful, cannot move 2 steps within one iteration:
            // Example:
            // ptrB = ptrB->next;
            // if ( ptrB == nullptr )
            // {
            //   ptrB = headA;
            // }
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }
        return ptrA;
    }
};

using ptr2getIntersectionNode = ListNode *( Solution::* )( ListNode *, ListNode * );


void
test( ptr2getIntersectionNode pfcn )
{
    // TODO: implement the test case here.
}


int
main()
{
    ptr2getIntersectionNode pfcn = &Solution::getIntersectionNode;
    test( pfcn );
}