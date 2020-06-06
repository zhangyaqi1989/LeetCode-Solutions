class Solution:     
    def maxSumSubmatrix(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        if not any(matrix):
            return 0
        m, n = len(matrix), len(matrix[0])
        res = float('-inf')
        for left in range(n):
            curcums = [0] * m
            right = left
            while right < n:
                for i in range(m):
                    curcums[i] += matrix[i][right]
                curarrmax = self.maxSubArrayLessK(curcums, k)
                res = max(res, curarrmax)
                right += 1
        return res
    
    def maxSubArrayLessK(self, nums, k):
            cumset = [0]
            maxsum = float('-inf')
            cursum = 0
            for i in range(len(nums)):
                cursum += nums[i]
                idx = bisect.bisect_left(cumset, cursum - k)
                if 0 <= idx < len(cumset):
                    maxsum = max(maxsum, cursum - cumset[idx])
                bisect.insort(cumset, cursum)
            return maxsum