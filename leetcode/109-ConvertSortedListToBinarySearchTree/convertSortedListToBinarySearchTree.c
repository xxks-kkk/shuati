/*
 * [Source]
 * 
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 *
 * [Problem Description]
 *
 * Given a singly linked list where elements are 
 * sorted in ascending order, convert it to a height balanced BST.
 *
 * [Related Questions]
 *
 * 1. Leetcode-141:
 *
 *    In 141, we use two pointers (one fast, one slow) to find if 
 *    the linked list has cycle. Here, we use two pointers to find
 *    the middle position of the list.
 *
 * [Companies]
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* createTreeNode(int val);
struct TreeNode* sortedListToBSTHelper(struct ListNode *head, struct ListNode *stop);

struct TreeNode*
sortedListToBST(struct ListNode* head)
{
  return sortedListToBSTHelper(head, NULL);
}

struct TreeNode*
sortedListToBSTHelper(struct ListNode *head,
                      struct ListNode *stop)
{
  struct ListNode *mid, *fast, *slow, *left, *right;
  struct TreeNode *root;
  if(head == stop) return NULL;
  fast = slow = head;
  while(fast != stop && fast->next != stop)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  mid = slow; // we find the mid position
  root = createTreeNode(mid->val);
  root->left = sortedListToBSTHelper(head, mid);
  root->right = sortedListToBSTHelper(mid->next, stop);
  return root;
}

struct TreeNode*
createTreeNode(int val)
{
  struct TreeNode *node = malloc(sizeof(struct TreeNode));
  node->val = val;
  node->left = node->right = NULL;
  return node;
}
