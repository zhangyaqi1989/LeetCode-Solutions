class Solution:
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        def valid(m, s):
            m -= 1
            acc = 0
            for num in nums:
                acc += num
                if acc > s:
                    m -= 1
                    acc = num
                    if m < 0:
                        return False
            return True
        l, r = max(nums), sum(nums)
        while l < r:
            mid = (l + r) // 2
            if valid(m, mid):
                r = mid
            else:
                l = mid + 1
        return l