#include "shared_headers.h"
#include <algorithm>

#define CAPACITY 3

/**
 * A circular array implementation of queue
 * @tparam Object
 */
template<class Object>
class Queue
{
public:
    /**
     *
     * @param capacity
     */
    Queue();

    /**
     * Destructor
     */
    ~Queue();

    void
    enqueue( const Object &x );

    Object
    dequeue();

    bool
    isEmpty() const;

    bool
    isFull() const;

    void
    printQueue();

    Object
    getFront();

    int
    getCurrSize();

private:
    Object theArray[CAPACITY]; // the array
    int front;                 // front of the queue
    int back;                  // back of the queue
    int currSize;              // the number of elements that are actually in the queue
    void init();
};

// Usually, the template class is implemented in the header
// We do this to have the implementation into a separate file
#include "queue.tpp"