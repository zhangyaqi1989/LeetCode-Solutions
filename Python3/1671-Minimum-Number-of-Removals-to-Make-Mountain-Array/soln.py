class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        # LIS + LDS
        n = len(nums)
        left_dp = [1] * n
        for i in range(1, n):
            mx = 1
            for j in range(i):
                if nums[i] > nums[j]:
                    mx = max(mx, left_dp[j] + 1)
            left_dp[i] = mx
        right_dp = [1] * n
        for i in range(n - 2, -1, -1):
            mx = 1
            for j in range(i + 1, n):
                if nums[i] > nums[j]:
                    mx = max(mx, right_dp[j] + 1)
            right_dp[i] = mx
        mn_delete = n
        for i in range(1, n - 1):
            if left_dp[i] >= 2 and right_dp[i] >= 2:
                mn_delete = min(mn_delete, n + 1 - left_dp[i] - right_dp[i])
        return mn_delete
