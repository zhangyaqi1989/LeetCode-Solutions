class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        two = one = None
        for i in range(len(nums) - 1):
            a = nums[i]
            b = nums[i + 1]
            if a > b:
                one, two = nums[:], nums[:]
                one[i] = b
                two[i + 1] = a
                break
        return (one == sorted(one) or two == sorted(two)) if one is not None else True