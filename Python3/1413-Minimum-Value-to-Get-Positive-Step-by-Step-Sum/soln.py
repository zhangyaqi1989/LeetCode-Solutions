class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        mn = math.inf
        cur = 0
        for num in nums:
            cur += num
            if cur < mn:
                mn = cur
        return max(1 - mn, 1)
