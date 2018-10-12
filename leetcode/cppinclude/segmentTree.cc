#include "segmentTree.h"

template<typename T>
SegmentTree<T>::SegmentTree(int numElements)
{
    _numElements = numElements;
    // - Index starts with 1
    // - Use an array of size 2n and ignore index 0
    // - the child nodes of a node at idx are the nodes at 2*idx and 2*idx+1
    // - the parent of the node at idx is at the node at idx/2
    data = std::vector<T>(_numElements * 2);
}

template<typename T>
SegmentTree<T>::SegmentTree(const std::vector<T> &values)
{
    _numElements = values.size();
    data = std::vector<T>(_numElements * 2);
    // We first move the data to the second half of the data vector
    std::copy(values.begin(), values.end(), data.begin() + _numElements);
    // idx 0 does nothing
    for (int idx = _numElements - 1; idx > 0; --idx)
    {
        data[idx] = std::min(data[idx * 2], data[idx * 2 + 1]);
    }
}

template<typename T>
T
SegmentTree<T>::minimum(int left, int right)
{
    left = left + _numElements;
    right = right + _numElements;
    // C++: generic way to specify max value for a template variable
    T minVal = std::numeric_limits<T>::max();
    while (left < right)
    {
        // invariant: min \in [left, right)
        if (left % 2 == 1)
        {
            // left is odd
            minVal = std::min(minVal, data[left]);
            left++;
        }
        if (right % 2 == 1)
        {
            // right is odd, we do right-- first because of the invariant:
            // not including the right bound
            right--;
            minVal = std::min(minVal, data[right]);
        }
        // move up to the parent
        right /= 2;
        left /= 2;
    }
    return minVal;
}

template<typename T>
void
SegmentTree<T>::update(int idx, T value)
{
    idx += _numElements;
    data[idx] = value;
    while (idx > 1)
    {
        idx /= 2;
        data[idx] = std::min(data[2 * idx], data[2 * idx + 1]);
    }
}

template<typename T>
T
SegmentTree<T>::getData(int idx)
{
    return data[idx+_numElements];
}

int
main()
{
    SegmentTree<int> tree = SegmentTree<int>(5);
    tree.update(0, 5);
    tree.update(1, 2);
    tree.update(2, 3);
    tree.update(3, 1);
    tree.update(4, 4);
    for (int i = 0; i < 5; i++)
    {
        assert(tree.minimum(i, i + 1) == tree.getData(i));
    }
    assert(tree.minimum(1, 4) == 1);
    tree.update(3, 10);
    assert(tree.minimum(1, 4) == 2);
    assert(tree.minimum(0, 5) == 2);
    tree.update(4, 0);
    assert(tree.minimum(1, 4) == 2);
    assert(tree.minimum(0, 5) == 0);

    SegmentTree<int> tree2({5, 2, 3, 1, 4});
}