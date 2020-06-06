class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        xor = 0
        for num in nums:
            xor ^= num
        return xor == 0 or len(nums) % 2 == 0
