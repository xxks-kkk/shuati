def binarySearch(nums, target):
    low, high = 0, len(nums) - 1
    while low <= high:
        mid = (low + high) / 2
        if target == nums[mid]:
            return mid
        elif target > nums[mid]:
            low = mid + 1
        else:
            high = mid - 1
    return -1

if __name__ == "__main__":
    s = [2,4,5,6,9]
    for i in range(len(s)):
        assert binarySearch(s, s[i]) == i