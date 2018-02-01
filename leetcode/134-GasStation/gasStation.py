# There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
#
# You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
# You begin the journey with an empty tank at one of the gas stations.
#
# Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
#
# Note:
# The solution is guaranteed to be unique.

class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        if sum(gas) < sum(cost):
            return -1
        total_gas = 0
        start_idx = 0
        for i in range(len(gas)):
            total_gas += (gas[i] - cost[i])
            if total_gas < 0:
                total_gas = 0
                start_idx = i + 1
        return start_idx


if __name__ == "__main__":
    sol = Solution()
    assert sol.canCompleteCircuit([2],[2]) == 0
    assert sol.canCompleteCircuit([3,1,2],[3,2,1]) == 2
    assert sol.canCompleteCircuit([1,2,3,3],[2,1,5,1]) == 3
    assert sol.canCompleteCircuit([6,1,4,3,5],[3,8,2,4,2]) == 2
    assert sol.canCompleteCircuit([1,2,3,3],[2,1,5,1]) == 3
    assert sol.canCompleteCircuit([2,4],[3,4]) == -1