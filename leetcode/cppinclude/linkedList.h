#include <vector>
#include <iostream>

// Primer: The only difference between using "class" and using "struct"
// to define a class is the default access level ("class": default private;
// "struct": default public (p.269)
struct ListNode
{
    int val;
    ListNode *next;

    // Primer: constructor initializer list (p.265)
    // specifies initial values for one or more data members of the object being created.
    // The constructor initializer is a list of member names, each of which is followed by that member's
    // initial value in parentheses. Multiple member initializations are separated by commas.
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList
{
public:
    LinkedList();
    ListNode *
    list2list(std::vector<int> nums);
    std::vector<int>
    printList(ListNode *head);
    void
    freeList(ListNode *&head);
private:
    ListNode *head;
};