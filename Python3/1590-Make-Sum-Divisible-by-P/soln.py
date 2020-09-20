class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total = sum(nums)
        if total % p == 0:
            return 0
        target = total % p
        # remove a longest subarrry such that sum(subarray) % p = target
        seen = {0 : -1}
        acc = 0
        mn = len(nums)
        for i, num in enumerate(nums):
            acc += num
            remain = acc % p
            need = (remain - target) % p
            if need in seen:
                mn = min(mn, i - seen[need])
            seen[remain] = i
        return -1 if mn == len(nums) else mn
