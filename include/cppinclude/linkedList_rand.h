#ifndef LINKEDLIST_RAND_H
#define LINKEDLIST_RAND_H

#include "shared_headers.h"

// Definition for a Node in linked list with random pointer
class Node
{
public:
  int val;
  std::shared_ptr<Node> next;
  std::shared_ptr<Node> random;

  Node() {}
  Node(int _val, std::shared_ptr<Node> _next, std::shared_ptr<Node> _random) :
    val(_val), next(_next), random(_random) {}
};

class LinkedListRandom
{
public:
  // transform the json representation of linked list into the linked list
  static std::shared_ptr<Node> list2list(const std::string &rawJson);
  // transform a linked list to the json representation of linked list
  static std::string printList(const std::shared_ptr<Node> &head);
  // delete the linked list
  static void freeList(std::shared_ptr<Node>& head);
};

#endif
