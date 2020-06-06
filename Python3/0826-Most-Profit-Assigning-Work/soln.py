class Solution:
    def maxProfitAssignment(self, difficulty, profit, worker):
        """
        :type difficulty: List[int]
        :type profit: List[int]
        :type worker: List[int]
        :rtype: int
        """
        pairs = list(zip(profit, difficulty))
        pairs.sort(key=lambda x : (-x[0], x[1]))
        i, n = 0, len(pairs)
        ans = 0
        for worker in sorted(worker, reverse=True):
            while i < n and pairs[i][1] > worker:
                i += 1
            if i < n:
                ans += pairs[i][0]
            else:
                break
        return ans
