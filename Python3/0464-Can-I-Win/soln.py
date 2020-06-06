class Solution:
    def canIWin(self, maxChoosableInteger, desiredTotal):
        """
        :type maxChoosableInteger: int
        :type desiredTotal: int
        :rtype: bool
        """
        memo = {}
        cands = set(range(1, maxChoosableInteger + 1))
        if sum(cands) < desiredTotal:
            return False
        def helper(cands, desiredTotal):
            pair = frozenset(cands), desiredTotal
            if pair in memo:
                return memo[pair]
            if max(cands) >= desiredTotal:
                ans = True
            else:
                if all(helper(cands - {item}, desiredTotal - item) for item in cands):
                    ans = False
                else:
                    ans = True
            memo[pair] = ans
            return ans
        return helper(cands, desiredTotal)