class Solution:
    def minOperations(self, nums: List[int]) -> int:
        # doubl all numbers
        def compute_min_steps(num):
            nadds, ndoubles = 0, 0
            while num:
                if num % 2:
                    nadds += 1
                    num -= 1
                else:
                    ndoubles += 1
                    num >>= 1
            return nadds, ndoubles
        ans = 0
        mx_ndoubles = 0
        for num in nums:
            nadds, ndoubles = compute_min_steps(num)
            ans += nadds
            mx_ndoubles = max(mx_ndoubles, ndoubles)
        return ans + mx_ndoubles
