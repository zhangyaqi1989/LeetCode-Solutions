class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        acc = 0
        seen = {0 : -1}
        for i, num in enumerate(nums):
            acc += num
            r = acc % k if k != 0 else acc
            if r in seen:
                if i - seen[r] >= 2:
                    return True
            else:
                seen[r] = i
        return False
