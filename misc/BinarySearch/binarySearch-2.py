def findFirstGreaterEqualTo(nums, target):
    # find the first index of a number that is greater than or equal to the given
    # target in the list
    low, high = 0, len(nums)
    while low < high:
        mid = (low + high) / 2
        if nums[mid] < target:
            low = mid + 1
        else:
            high = mid
    return high

def findFirstGreaterTo(nums, target):
    # find the first index of a number that is greater than the given
    # target in the list
    low, high = 0, len(nums)
    while low < high:
        mid = (low + high) / 2
        if nums[mid] <= target:
            low = mid + 1
        else:
            high = mid
    return -1 if high == len(nums) else high

if __name__ == "__main__":
    s = [2,4,5,6,9]
    assert findFirstGreaterEqualTo(s, 3) == 1
    assert findFirstGreaterTo(s, 3) == 1
    s = [0,1,1,1,1]
    assert findFirstGreaterEqualTo(s, 1) == 1
    assert findFirstGreaterTo(s, 1) == -1