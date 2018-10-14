//    Design a data structure that supports all following operations in average O(1) time.
//
//    insert(val): Inserts an item val to the set if not already present.
//    remove(val): Removes an item val from the set if present.
//    getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
//    Example:
//
//    // Init an empty set.
//    RandomizedSet randomSet = new RandomizedSet();
//
//    // Inserts 1 to the set. Returns true as 1 was inserted successfully.
//    randomSet.insert(1);
//
//    // Returns false as 2 does not exist in the set.
//    randomSet.remove(2);
//
//    // Inserts 2 to the set, returns true. Set now contains [1,2].
//    randomSet.insert(2);
//
//    // getRandom should return either 1 or 2 randomly.
//    randomSet.getRandom();
//
//    // Removes 1 from the set, returns true. Set now contains [2].
//    randomSet.remove(1);
//
//    // 2 was already in the set, so return false.
//    randomSet.insert(2);
//
//    // Since 2 is the only number in the set, getRandom always return 2.
//    randomSet.getRandom();

#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <cassert>

using namespace std;

class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool
    insert(int val)
    {
        if (m.find(val) != m.end())
        {
            return false;
        }
        vec.push_back(val);
        m[val] = vec.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool
    remove(int val)
    {
        if (m.find(val) == m.end())
        {
            return false;
        }
        // The idea is to replace the to-be-deleted val with the last value of the vector
        // Then, we can remove the last value of the vector
        int last = vec.back();
        m[last] = m[val];
        vec[m[val]] = last;
        vec.pop_back();
        m.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int
    getRandom()
    {
        return vec[rand() % vec.size()];
    }
private:
    // <val, pos in the list>
    unordered_map<int, int> m;
    vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

void test()
{
    auto randomSet = new RandomizedSet();
    assert(randomSet->insert(1));
    assert(!randomSet->remove(2));
    assert(randomSet->insert(2));
    randomSet->getRandom();
    assert(randomSet->remove(1));
    assert(!randomSet->insert(2));
    randomSet->getRandom();
}

int main()
{
    test();
}