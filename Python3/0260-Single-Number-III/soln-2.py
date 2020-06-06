import functools
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor = functools.reduce(operator.xor, nums, 0)
        # last bit
        xor = xor & (-xor)
        x = y = 0
        for num in nums:
            if num & xor:
                x ^= num
            else:
                y ^= num
        return [x, y]
