class Solution:
    def findMaxAverage(self, nums, K):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        N = len(nums)
        acc = [0]
        for num in nums:
            acc.append(acc[-1] + num)
        def d(x, y):
            return (acc[y + 1] - acc[x]) / (y + 1 - x)
        hull = collections.deque()
        ans = float('-inf')
        for j in range(K - 1, N):
            while len(hull) >= 2 and d(hull[-2], hull[-1] - 1) >= d(hull[-2], j - K):
                hull.pop()
            hull.append(j - K + 1)
            while len(hull) >= 2 and d(hull[0], hull[1] - 1) <= d(hull[0], j):
                hull.popleft()
            ans = max(ans, d(hull[0], j))
        return ans