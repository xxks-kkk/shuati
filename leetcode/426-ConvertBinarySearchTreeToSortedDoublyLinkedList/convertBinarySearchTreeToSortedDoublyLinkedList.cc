class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution
{
public:
    Node *
    treeToDoublyList(Node *root)
    {
        if(root == nullptr)
        {
            return root;
        }
        Node* head = nullptr;
        Node* prev = nullptr;
        inorder(root, head, prev);
        // prev will now point to the rightmost node
        // head will point to the leftmost node
        head->left = prev;
        prev->right = head;
        return head;
    }
private:
    void inorder(Node* node, Node*& head, Node*& prev)
    {
        // the leftmost node of the tree is head
        if(head == nullptr && node->left == nullptr)
        {
            head = node;
            prev = node;
        }
        // Below two steps are critical as the node's left and
        // right children may change when we form the doubly linked list
        Node* left = node->left;
        Node* right = node->right;
        // process left subtree
        if (left != nullptr)
        {
            inorder(left, head, prev);
        }
        // process the current node
        node->left = prev;
        prev->right = node;
        // this step is critical
        prev = node;
        if (right)
        {
            inorder(right, head, prev);
        }
    }
};

int main()
{
    //TODO: implement unit test
}