//    Implement the following operations of a queue using stacks.
//
//    push(x) -- Push element x to the back of queue.
//    pop() -- Removes the element from in front of queue.
//    peek() -- Get the front element.
//    empty() -- Return whether the queue is empty.
//    Example:
//
//    MyQueue queue = new MyQueue();
//
//    queue.push(1);
//    queue.push(2);
//    queue.peek();  // returns 1
//    queue.pop();   // returns 1
//    queue.empty(); // returns false
//    Notes:
//
//    You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
//    Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
//    You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

#include <stack>
#include <cassert>

// Approach 1
class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {

    }


    /** Push element x to the back of queue. */
    void
    push( int x )
    {
        if ( s1.empty())
        {
            s1.push( x );
            return;
        }
        while ( !s1.empty())
        {
            s2.push( s1.top());
            s1.pop();
        }
        s1.push( x );
        while ( !s2.empty())
        {
            s1.push( s2.top());
            s2.pop();
        }
    }


    /** Removes the element from in front of queue and returns that element. */
    int
    pop()
    {
        int res = s1.top();
        s1.pop();
        return res;
    }


    /** Get the front element. */
    int
    peek()
    {
        return s1.top();
    }


    /** Returns whether the queue is empty. */
    bool
    empty()
    {
        return s1.empty() && s2.empty();
    }


private:
    std::stack<int> s1;
    std::stack<int> s2;
};

// Approach 2
class MyQueue2
{
public:
    /** Initialize your data structure here. */
    MyQueue2()
    {

    }


    /** Push element x to the back of queue. */
    void
    push( int x )
    {
        if (s1.empty())
        {
            front = x;
        }
        s1.push(x);
    }


    /** Removes the element from in front of queue and returns that element. */
    int
    pop()
    {
        if (s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int res = s2.top();
        s2.pop();
        return res;
    }


    /** Get the front element. */
    int
    peek()
    {
        if(!s2.empty())
        {
            return s2.top();
        }
        return front;
    }


    /** Returns whether the queue is empty. */
    bool
    empty()
    {
        return s1.empty() && s2.empty();
    }


private:
    std::stack<int> s1;
    std::stack<int> s2;
    int front;
};


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
void
test()
{
    auto obj = new MyQueue{};
    obj->push( 1 );
    obj->push( 2 );
    assert( obj->peek() == 1 );
    assert( obj->pop() == 1 );
    assert( !obj->empty());

    auto obj2 = new MyQueue2{};
    obj2->push( 1 );
    obj2->push( 2 );
    assert( obj2->peek() == 1 );
    assert( obj2->pop() == 1 );
    assert( !obj->empty());
}


int
main()
{
    test();
}