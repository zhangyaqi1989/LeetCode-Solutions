class Solution(object):
    def lastStoneWeightII(self, stones):
        dp = {0}
        for stone in stones:
            dp = {stone + item for item in dp} | {stone - item for item in dp}
        return min(abs(x) for x in dp)
