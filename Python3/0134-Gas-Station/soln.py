class Solution:
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        if sum(cost) > sum(gas): return -1
        start, accumulate = 0, 0
        for i, (g, c) in enumerate(zip(gas, cost)):
            cur = g - c
            if accumulate + cur < 0:
                start = i + 1
                accumulate = 0
            else:
                accumulate += cur
        return start