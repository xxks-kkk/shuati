//    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//    push(x) -- Push element x onto stack.
//    pop() -- Removes the element on top of the stack.
//    top() -- Get the top element.
//    getMin() -- Retrieve the minimum element in the stack.
//
//    Example:
//    MinStack minStack = new MinStack();
//    minStack.push(-2);
//    minStack.push(0);
//    minStack.push(-3);
//    minStack.getMin();   --> Returns -3.
//    minStack.pop();
//    minStack.top();      --> Returns 0.
//    minStack.getMin();   --> Returns -2.

#include <stack>
#include <cassert>
#include <climits>

// two stack solution
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        if(s2.empty() || x <= getMin())
        {
            s2.push(x);
        }
        s1.push(x);
    }

    void pop() {
        if(s1.top() == getMin())
        {
            s2.pop();
        }
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }
private:
    std::stack<int> s1;
    std::stack<int> s2;
};

// one stack solution
class MinStack2 {
public:
    /** initialize your data structure here. */
    MinStack2() {

    }

    void push(int x) {
        // only push the old minimum value when the current
        // minimum value changes after pushing the new value x
        if(x <= getMin())
        {
            s.push(min);
            min = x;
        }
        s.push(x);
    }

    void pop() {
        if(s.top() == min)
        {
            // if pop operation could result in the changing of the current minimum value,
            // pop twice and change the current minimum value to the last minimum value.
            s.pop();
            min = s.top();
            s.pop();
        }
        else
        {
            s.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min;
    }
private:
    int min = INT_MAX;
    std::stack<int> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
int main()
{
    MinStack obj = MinStack();
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    assert(obj.getMin() == -3);
    obj.pop();
    assert(obj.top() == 0);
    assert(obj.getMin() == -2);

    MinStack2 obj2 = MinStack2();
    obj2.push(-2);
    obj2.push(0);
    obj2.push(-3);
    assert(obj2.getMin() == -3);
    obj2.pop();
    assert(obj2.top() == 0);
    assert(obj2.getMin() == -2);
}