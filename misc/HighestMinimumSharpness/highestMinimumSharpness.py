

class Solution:
    def highestMinimumSharpness(self, matrix):
        pass

if __name__ == "__main__":
    sol = Solution()
    test1 = [[0.5, 0.7, 0.2], [0.7, 0.5, 0.8], [0.9, 0.1, 0.5]]
    assert sol.highestMinimumSharpness(test1) == 0.7
    test2 = [[4, 5, 4, 0, 1, 2],
             [5, 6, 5, 0, 0, 0],
             [0, 0, 0, 0, 0, 0],
             [1, 3, 1, 2, 3, 3],
             [3, 0, 3, 0, 0, 0]]
    assert sol.highestMinimumSharpness(test2) == 2