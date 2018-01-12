def binarySearch(nums, target):
    low, high = 0, len(nums) - 1
    while low <= high:
        mid = low + (high-low) // 2
        if target == nums[mid]:
            return mid
        elif target > nums[mid]:
            low = mid + 1
        else:
            high = mid - 1
    return -1

def binarySearch2(nums, target):
    low, high = 0, len(nums)
    while low < high:
        mid = low + (high - low) // 2
        if target == nums[mid]:
            return mid
        elif target > nums[mid]:
            low = mid + 1
        else:
            high = mid
    return -1

if __name__ == "__main__":
    s = [2,4,5,6,9,11, 13, 40, 40, 102]
    for i in range(len(s)):
        print(binarySearch(s, s[i]))
    assert binarySearch(s, 10) == -1

    for i in range(len(s)):
        print(binarySearch2(s, s[i]))
    assert binarySearch2(s, 10) == -1