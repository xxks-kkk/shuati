#include <stack>

using namespace std;

class MaxStack
{
public:
  /** initialize your data structure here. */
  MaxStack()
  {
  }

  void push(int x)
  {
    int max = maxStack.empty()? x : maxStack.top();
    maxStack.emplace(max > x ? max: x);
    stk.emplace(x);
  }

  int pop()
  {
    int pop_element = stk.top();
    maxStack.pop();
    stk.pop();
    return pop_element;
  }

  int top()
  {
    return stk.top();
  }

  int peekMax()
  {
    return maxStack.top();
  }

  int popMax()
  {
    int max = peekMax();
    stack<int> buffer;
    while(top() != max) buffer.emplace(pop());
    pop();
    while(!buffer.empty()) {
      push(buffer.top());
      buffer.pop();
    }
    return max;
  }

private:
  stack<int> stk;
  stack<int> maxStack;
};

void test() {
  MaxStack* stack = new MaxStack();
  stack->push(5);
  stack->push(1);
  stack->push(5);
  assert(stack->top() == 5);
  assert(stack->popMax() == 5);
  assert(stack->top() == 1);
  assert(stack->peekMax() == 5);
  assert(stack->pop() == 1);
  assert(stack->top() == 5);
}

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
int main()
{
  test();
}
