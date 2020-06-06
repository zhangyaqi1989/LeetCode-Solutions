class Solution:
    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        total = sum(nums)
        subsum, rem = divmod(total, k)
        if rem != 0:
            return False
        nums.sort(reverse=True)
        sums = [0] * k
        def helper(i):
            if i == len(nums):
                return len(set(sums)) == 1
            for j in range(k):
                sums[j] += nums[i]
                if sums[j] <= subsum and helper(i + 1):
                    return True
                sums[j] -= nums[i]
                if sums[j] == 0:
                    break
            return False
        return helper(0)