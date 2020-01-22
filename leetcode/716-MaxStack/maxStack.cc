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
    element_with_cached_max_.emplace(ElementWithCachedMax{x, element_with_cached_max_.empty() ? x : peekMax()});
  }

  int pop()
  {
    int pop_element = element_with_cached_max_.top().element;
    element_with_cached_max_.pop();
    return pop_element;
  }

  int top()
  {
    return element_with_cached_max_.top().element;
  }

  int peekMax()
  {
    return element_with_cached_max_.top().max;
  }

  int popMax()
  {
    stack<ElementWithCachedMax> buffer;
    while (element_with_cached_max_.top().element != element_with_cached_max_.top().max)
    {
      buffer.emplace(element_with_cached_max_.top());
      element_with_cached_max_.pop();
    }
    int pop_max = element_with_cached_max_.top().element;
    element_with_cached_max_.pop();
    while (!buffer.empty())
    {
      element_with_cached_max_.emplace(buffer.top());
      buffer.pop();
    }
    return pop_max;
  }

private:
  struct ElementWithCachedMax
  {
    int element, max;
  };
  stack<ElementWithCachedMax> element_with_cached_max_;
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
