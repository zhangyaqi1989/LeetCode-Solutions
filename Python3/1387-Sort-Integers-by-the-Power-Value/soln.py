from functools import lru_cache
class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        @lru_cache(None)
        def compute_power_value(num):
            if num == 1:
                return 0
            if num & 1:
                return compute_power_value(num * 3 + 1) + 1
            else:
                return compute_power_value(num // 2) + 1
        powers = {num : compute_power_value(num) for num in range(lo, hi + 1)}
        nums = sorted(range(lo, hi + 1), key=lambda num : (powers[num], num))
        return nums[k - 1]
