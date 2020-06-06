class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = []
        for i in range(0, n, 2):
            a, b = nums[i], nums[i + 1]
            if a != 0:
                ans.extend([b] * a)
        return ans
