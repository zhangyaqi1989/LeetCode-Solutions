class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        lo = - k - 1
        for i, num in enumerate(nums):
            if num == 1:
                if i - lo - 1 < k:
                    return False
                lo = i
        return True
