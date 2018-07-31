#include "queue.h"
#include <cassert>

int main()
{
    auto q = std::unique_ptr<Queue<int>>(new Queue<int>());
    q->enqueue(4);
    q->printQueue();
    q->enqueue(5);
    q->printQueue();
    q->enqueue(2);
    q->printQueue();
    assert(q->isFull());
    q->dequeue();
    q->printQueue();
    q->enqueue(3);
    q->printQueue();
    assert(q->getFront() == 5);
    q->dequeue();
    q->printQueue();
    q->dequeue();
    q->printQueue();
    q->dequeue();
    q->printQueue();
    assert(q->isEmpty());
    q->enqueue(6);
    q->printQueue();
    auto r = std::unique_ptr<Queue<char>>(new Queue<char>());
    r->enqueue('h');
    r->enqueue('z');
    r->enqueue('y');
    assert(r->getCurrSize() == 3);
}