class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        odd = 0
        even = 0
        for i, num in enumerate(nums):
            if i % 2 == 0:
                even += num
            else:
                odd += num
        left_odd = 0
        left_even = 0
        ans = 0
        for i, num in enumerate(nums):
            if i % 2 == 0:
                temp_odd = left_odd + even - num
                temp_even = left_even + odd
            else:
                temp_odd = left_odd + even
                temp_even = left_even + odd - num
            ans += temp_odd == temp_even
            if i % 2 == 0:
                left_even += num
                even -= num
            else:
                left_odd += num
                odd -= num
        return ans
