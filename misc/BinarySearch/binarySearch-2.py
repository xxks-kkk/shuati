def findFirstGreaterEqualTo(nums, target):
    # find the first index of a number that is greater than or equal to the given
    # target in the list
    low, high = 0, len(nums)
    while low < high:
        mid = (low + high) / 2
        if nums[mid] < target:
            low = mid + 1
        else: # nums[mid] >= target
            high = mid
    return -1 if high == len(nums) else high

def findFirstGreaterTo(nums, target):
    # find the first index of a number that is greater than the given
    # target in the list
    low, high = 0, len(nums)
    while low < high:
        mid = low + (high - low) // 2
        if nums[mid] <= target:
            low = mid + 1
        else: # nums[mid] > target
            high = mid
    return -1 if high == len(nums) else high

def findFirstOfRepeatTargets(nums, target):
    # find the first of a repeated series of the target. For example, given array
    # is [1,2,3,3,5,6,9] and the target is "3". Then this function returns the 1st "3" instead of
    # the 2nd "3".
    # invariant: a[lo] < target <= a[hi] || target does not exist
    # https://stackoverflow.com/questions/26564658/binary-search-and-invariant-relation
    low, high = -1, len(nums)-1
    while high - low > 1:
        mid = low + (high - low) // 2
        if nums[mid] >= target:
            high = mid
        else:
            low = mid
    return high if high > low and nums[high] == target else -1

if __name__ == "__main__":
    s = [2,4,5,6,9]
    assert findFirstGreaterEqualTo(s, 3) == 1
    assert findFirstGreaterTo(s, 10) == -1
    assert findFirstGreaterTo(s, 3) == 1
    s = [0,1,1,1,1]
    assert findFirstGreaterEqualTo(s, 1) == 1
    assert findFirstGreaterTo(s, 1) == -1
    s = [0,1,1,3,3]
    assert findFirstOfRepeatTargets(s, 3) == 3
    s = [0,1,5,7,8,10,12,15]
    assert findFirstGreaterTo(s, 3) == 2