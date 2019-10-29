#ifndef LINKEDLIST_RAND_H
#define LINKEDLIST_RAND_H

#include "shared_headers.h"

// Definition for a Node in linked list with random pointer
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class LinkedListRandom
{
public:
  // transform the json representation of linked list into the linked list
  static Node* list2list(const char*  json);
  // transform a linked list to the json representation of linked list
  static std::string printList(Node* head);
  // delete the linked list
  static void freeList(Node* &head);
};


#endif
