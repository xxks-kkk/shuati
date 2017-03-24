/*
 * [Source]
 * 
 * https://leetcode.com/problems/add-two-numbers/
 *
 * [Problem Description]
 *
 * You are given two non-empty linked lists representing two non-negative 
 * integers. The digits are stored in reverse order 
 * and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.

 * You may assume the two numbers do not contain any leading zero, 
 * except the number 0 itself.

 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 * [Companies]
 */

#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};


void addDigit(int val, struct ListNode *ptr);
struct ListNode*  makeEmpty();

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode*
addTwoNumbers(struct ListNode* l1,
              struct ListNode* l2)
{
  struct ListNode* dummyA = l1;
  struct ListNode* dummyB = l2;
  struct ListNode* R = makeEmpty();
  struct ListNode* dummyR = R;
  int digitSum = 0;
  int carry = 0;
  int x, y;

  while(dummyA != NULL || dummyB != NULL)
  {
    (dummyA != NULL) ? (x = dummyA->val) : (x = 0);
    (dummyB != NULL) ? (y = dummyB->val) : (y = 0);

    digitSum = x + y + carry;
    carry = digitSum / 10;
    addDigit(digitSum % 10, dummyR);
    
    if (dummyA != NULL) dummyA = dummyA->next;
    if (dummyB != NULL) dummyB = dummyB->next;
    dummyR = dummyR->next;    
  }

  if (carry == 1)
  {
    addDigit(carry, dummyR);
    dummyR = dummyR->next;
  }

  return R->next; // this is clever: we can still use sentinel node even the OJ expects us to use none-sentinel node linked list implementation.
}

void
addDigit(int val,
         struct ListNode *ptr)
{
  struct ListNode* tmp;
  tmp = malloc(sizeof(struct ListNode));
  tmp->val = val;
  tmp->next = NULL;
  ptr->next = tmp;
}

struct ListNode*
makeEmpty()
{
  struct ListNode* tmp;
  tmp = malloc(sizeof(struct ListNode));
  tmp->next = NULL;
  return tmp;
}


//////// TEST DRIVER /////////
static void printIntegerList(struct ListNode *L);
struct ListNode* initializeInteger(int digits[], int numDigits);


int main()
{
  int l1[] = {2,4,3};
  int l2[] = {5,6,4};
  struct ListNode* l1List = initializeInteger(l1, 3);
  struct ListNode* l2List = initializeInteger(l2, 3);
  struct ListNode* result = addTwoNumbers(l1List, l2List);
  printIntegerList(result);

  return 0;
}

static void
printIntegerList(struct ListNode *L)
{
  if(L == NULL)
  {
    return;
  }
  printIntegerList(L->next);
  printf("%d", L->val);
}

struct ListNode*
initializeInteger(int digits[], int numDigits)
{
  int i;
  struct ListNode* R = makeEmpty();
  struct ListNode *P = R;

  R->val = digits[0];
  
  for(i=1 ; i < numDigits; i++)
  {
    addDigit(digits[i], P);
    P = P->next;
  }

  return R;
}
