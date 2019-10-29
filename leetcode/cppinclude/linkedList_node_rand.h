#ifndef LINKEDLIST_NODE_RAND_H
#define LINKEDLIST_NODE_RAND_H

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

#endif
