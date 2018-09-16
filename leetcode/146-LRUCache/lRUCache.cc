//    Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
//
//    get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//    put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
//    Follow up:
//    Could you do both operations in O(1) time complexity?
//
//    Example:
//
//    LRUCache cache = new LRUCache( 2 /* capacity */ );
//
//    cache.put(1, 1);
//    cache.put(2, 2);
//    cache.get(1);       // returns 1
//    cache.put(3, 3);    // evicts key 2
//    cache.get(2);       // returns -1 (not found)
//    cache.put(4, 4);    // evicts key 1
//    cache.get(1);       // returns -1 (not found)
//    cache.get(3);       // returns 3
//    cache.get(4);       // returns 4

#include <unordered_map>
#include <list>
#include <cassert>

using namespace std;

class LRUCache
{
public:
    LRUCache( int capacity )
    {
        _capacity = capacity;
    }


    int
    get( int key )
    {
        auto item = _cache.find( key );
        // if the key doesn't exist, we return -1;
        if ( item == _cache.end())
        {
            return -1;
        }
        // if the key exists, we need to update the LRU
        // and then we return the value
        use( item );
        return item->second.first;
    }


    void
    put( int key, int value )
    {
        auto item = _cache.find( key );
        // if the key already exists, we need to update the LRU
        // and update the value and the iterator pointing to the new location of the key
        if ( item != _cache.end())
        {
            use( item );
            _cache[key] = {value, _lru.begin()};
            return;
        }
        // if the key doesn't exist, we need to check the capacity first
        if ( _cache.size() == _capacity )
        {
            // if there isn't enough space, we kick out the least recently used from LRU
            // before we insert the new element
            _cache.erase( _lru.back());
            _lru.pop_back();
        }

        _lru.push_front( key );
        _cache[key] = {value, _lru.begin()};

    }


private:
    void
    use( unordered_map<int, pair<int, list<int>::iterator>>::iterator &it )
    {
        // suppose _lru: 1 - 2 - 3 and we access 2. After 2 being accessed,
        // _lru should look like: 2 - 1 - 3
        // We can remove 2 from 1-2-3 and add 2 back to the beginning of the list.
        // Since list is implemented as a doubly-linked list. We can do deletion
        // and add in O(1) as long as we have iterator pointing to the key we're about to delete.
        _lru.erase( it->second.second );
        _lru.push_front( it->first );
        // We also need to update the iterator to pointing to the new location of the key in the list.
        it->second.second = _lru.begin();
    }


    int _capacity;
    // < key, <value, key iterator pointing to the location of the key in _lru>>
    unordered_map<int, pair<int, list<int>::iterator>> _cache;
    // list of keys, first = Most Recently Used, last = Least Recently Used
    list<int> _lru;
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */


int
main()
{
    auto obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    assert(obj->get(1) == 1);
    obj->put(3,3);
    assert(obj->get(2) == -1);
    obj->put(4,4);
    assert(obj->get(3) == 3);
    assert(obj->get(4) == 4);
}