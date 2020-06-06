class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2:
            return False
        target = total // 2
        s = {0}
        for num in nums:
            s |= {x + num for x in s if x + num <= target}
            if target in s:
                return True
        return False
