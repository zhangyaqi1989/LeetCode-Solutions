class Solution:
    def splitArray(self, nums: List[int]) -> bool:
        n = len(nums)
        s = [0] * (n + 1)
        for i in range(n):
            s[i + 1] = s[i] + nums[i]
        def check(l, r):
            return {s[j] - s[l] for j in range(l + 1, r + 1) if s[j] - s[l] == s[r + 1] - s[j + 1]}
        return any(check(0, j - 1) & check(j + 1, n - 1) for j in range(n))
