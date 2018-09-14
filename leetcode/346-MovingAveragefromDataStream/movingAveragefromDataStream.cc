//
//    Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
//
//    Example:
//
//    MovingAverage m = new MovingAverage(3);
//    m.next(1) = 1
//    m.next(10) = (1 + 10) / 2
//    m.next(3) = (1 + 10 + 3) / 3
//    m.next(5) = (10 + 3 + 5) / 3

#include <queue>
#include <cassert>

using namespace std;

class MovingAverage
{
public:
    /** Initialize your data structure here. */
    MovingAverage( int size )
    {
        sum = 0;
        qsize = size;
    }


    double
    next( int val )
    {
        q.push( val );
        sum += val;
        if ( q.size() > qsize )
        {
            sum -= q.front();
            q.pop();
        }
        return sum / q.size();
    }


private:
    queue<int> q;
    double sum;
    int qsize;
};


/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

int
main()
{
    MovingAverage obj = MovingAverage( 3 );
    assert ( obj.next( 1 ) == 1 );
    assert( obj.next( 10 ) == (10 + 1) / 2.0 );
    assert( obj.next( 3 ) == (1 + 10 + 3) / 3.0 );
    assert( obj.next( 5 ) == (10 + 3 + 5) / 3.0 );
}