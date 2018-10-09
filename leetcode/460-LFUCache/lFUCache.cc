//    Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.
//
//    get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//    put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity,
//    it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem,
//    when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.
//
//    Follow up:
//    Could you do both operations in O(1) time complexity?
//
//    Example:
//
//    LFUCache cache = new LFUCache( 2 /* capacity */ );
//
//    cache.put(1, 1);
//    cache.put(2, 2);
//    cache.get(1);       // returns 1
//    cache.put(3, 3);    // evicts key 2
//    cache.get(2);       // returns -1 (not found)
//    cache.get(3);       // returns 3.
//    cache.put(4, 4);    // evicts key 1.
//    cache.get(1);       // returns -1 (not found)
//    cache.get(3);       // returns 3
//    cache.get(4);       // returns 4

#include <cassert>
#include <list>
#include <unordered_map>

using namespace std;

/**
 * m :      key <-> {val, freq}
 * mIter:   key <-> {list iterator}
 * fm:      fm  <-> {list of keys}
 *
 *            time
 *        ------------------------->
 *
 *        1 - [key] - [key] - [key]
 *  freq  2 - ...
 *        3 - ...
 *        4 - ...
 */

class LFUCache
{
public:
    LFUCache(int capacity)
    {
        _capacity = capacity;
        size = 0;
    }

    int
    get(int key)
    {
        if (m.count(key) == 0)
        {
            // key not inside the cache
            return -1;
        }
        // Since we accessed the key, we need to update the frequency mapping
        // let first erase the key from its original frequency mapping
        fm[m[key].second].erase(mIter[key]);
        // We update the frequency
        m[key].second++;
        // We put the key to the right frequency mapping spot (becasue we updated frequency)
        fm[m[key].second].push_back(key);
        // We also need to update the iterator of key
        mIter[key] = --fm[m[key].second].end();

        // Since we update the frequency and the key could be in the fm[minFreq] list,
        // we need to update the minFreq
        if (fm[minFreq].size() == 0)
        {
            minFreq++;
        }

        return m[key].first;
    }

    void
    put(int key, int value)
    {
        if (_capacity <= 0)
        {
            return;
        }

        // We fetch the old value here: if the key exists, we also update the key's frequency during the fetching
        // if the key doesn't exist, we return -1
        int storedValue = get(key);
        if (storedValue != -1)
        {
            // We already update the frequency during the get(key)
            // We only need to update the value
            m[key].first = value;
            return;
        }

        // We get here because we need to add new <key, value> pair
        if (size >= _capacity)
        {
            // We need to delete the LFU key
            m.erase(fm[minFreq].front());
            mIter.erase(fm[minFreq].front());
            fm[minFreq].pop_front();
            size--;
        }

        // We have space and we can now insert the key
        minFreq = 1;
        m[key] = {value, 1};
        fm[minFreq].push_back(key);
        mIter[key] = --fm[minFreq].end();
        size++;
    }
private:
    // size of the cache
    int _capacity;
    // number of keys currently in the cache
    int size;
    // the minimal frequency
    int minFreq;
    // <key, <value, freq>>
    unordered_map<int, pair<int,int>> m;
    // <key, list iterator>
    unordered_map<int, list<int>::iterator> mIter;
    // <freq, list of keys>
    unordered_map<int, list<int>> fm;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int
main()
{
    auto obj = new LFUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    assert(obj->get(1) == 1);   // returns 1
    obj->put(3,3);              // evicts 2
    assert(obj->get(2) == -1);  // return -1
    assert(obj->get(3) == 3);   // return 3
    obj->put(4,4);              // evict 1
    assert(obj->get(1) == -1);  // return -1
    assert(obj->get(3) == 3);   // return 3
    assert(obj->get(4) == 4);   // return 4
}