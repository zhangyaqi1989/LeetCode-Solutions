class Solution:
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        memo = {}
        def helper(pos, step):
            if (pos, step) in memo:
                return memo[pos, step]
            for i in range(pos + 1, len(stones)):
                gap = stones[i] - stones[pos]
                if gap < step - 1: continue
                if gap > step + 1:
                    memo[pos, step] = False
                    return False
                if helper(i, gap):
                    memo[pos, step] = True
                    return True
            memo[pos, step] = (pos == len(stones) - 1)
            return memo[pos, step]
        return helper(pos=0, step=0)