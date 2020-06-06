class Solution(object):
    def makesquare(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # divided into 4 equal
        s = sum(nums)
        q, r = divmod(s, 4)
        if len(nums) < 4 or r != 0:
            return False
        subs = [0] * 4
        def helper(idx, nums, subs, q):
            if idx == len(nums):
                return True
            else:
                for i in range(4):
                    if subs[i] + nums[idx] > q:
                        continue
                    subs[i] += nums[idx]
                    if helper(idx + 1, nums, subs, q):
                        return True
                    subs[i] -= nums[idx]
                return False
        nums = sorted(nums, reverse=True)
        return helper(0, nums, subs, q)
