template<typename Object>
Queue<Object>::Queue()
{
    init();
}

template<typename Object>
Queue<Object>::~Queue() = default;

template<typename Object>
Object
Queue<Object>::dequeue()
{
    if ( isEmpty())
    {
        throw std::invalid_argument( "The queue is empty" );
    }
    int old_front = front;
    front = (front + 1) % CAPACITY;
    currSize--;
    return theArray[old_front];
}


template<typename Object>
void
Queue<Object>::enqueue( const Object &x )
{
    if ( isFull())
    {
        throw std::invalid_argument( "The queue is full" );
    }
    theArray[back] = x;
    back = (back + 1) % CAPACITY;
    currSize++;
}

template<typename Object>
bool
Queue<Object>::isEmpty() const
{
    return currSize == 0;
}

template<typename Object>
bool
Queue<Object>::isFull() const
{
    return currSize == CAPACITY;
}

template<typename Object>
void
Queue<Object>::init()
{
    currSize = 0;
    front = 0;
    back = 0;
}

template<typename Object>
void
Queue<Object>::printQueue()
{
    std::cout << "[";
    for(int i = 0; i < currSize; ++i)
    {
        std::cout << theArray[(front + i)%CAPACITY] << ",";
    }
    std::cout << "]" << std::endl;
}

template<typename Object>
Object
Queue<Object>::getFront()
{
    return theArray[front];
}