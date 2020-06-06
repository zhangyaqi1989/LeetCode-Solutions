class Solution:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        ans = []
        combo = []
        def helper(combo, ans):
            if len(combo) == k:
                ans.append(combo[:])
            else:
                start = 1 if not combo else combo[-1] + 1
                for num in range(start, n + 1):
                    combo.append(num)
                    helper(combo, ans)
                    combo.pop()
        helper(combo, ans)
        return ans
