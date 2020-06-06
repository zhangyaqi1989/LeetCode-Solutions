class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        target, rem = divmod(s, 2)
        if rem:
            return False
        nums.sort(reverse=True)
        if nums[0] > target:
            return False
        seen = {0}
        for num in nums:
            seen |= {item + num for item in seen}
            if target in seen:
                return True
        return False
