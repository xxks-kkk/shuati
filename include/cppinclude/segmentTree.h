// Inspired by https://github.com/jakobkogler/Algorithm-DataStructures/blob/master/RangeQuery/SegmentTree.cpp
// YouTube video: https://youtu.be/Oq2E2yGadnU

#include "shared_headers.h"

template <typename T>
class SegmentTree {
public:
    /**
     * Create an empty segment tree that contains numElements nodes
     * @param numElements number of nodes in the segment tree
     */
    explicit SegmentTree(int numElements);

    /**
     * Create a segment tree from the given vector
     * @param values a vector
     */
    explicit SegmentTree(const std::vector<T>& values);

    /**
     * Update the value at idx of vector contained in the segment tree
     * @param idx the index
     * @param value  the to-be-updated value
     */
    void update(int idx, T value);

    /**
     * Find the minimum value for the range [left, right)
     * @param left
     * @param right
     * @return the minimum value within the range
     */
    T minimum(int left, int right);

    /**
     * Return the value at given idx
     * @param idx the idx of the value
     * @return
     */
    T getData(int idx);
private:
    int _numElements;
    std::vector<T> data;
};