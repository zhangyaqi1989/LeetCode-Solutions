class Solution:
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # binary search
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] < nums[mid + 1]:
                if (mid - l) % 2: # even left
                    l = mid + 1
                else:
                    r = mid
            else: # nums[mid] == nums[mid + 1]
                if (mid - l) % 2:
                    r = mid - 1
                else:
                    l = mid + 2
        return nums[l]