class Solution:
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        def valid(largest_sum):
            cnt = 1
            cur = 0
            for num in nums:
                cur += num
                if cur > largest_sum:
                    if cnt >= m:
                        return False
                    else:
                        cnt += 1
                        cur = num
            return True
        l = max(nums)
        r = sum(nums)
        while l < r:
            mid = (l + r) >> 1
            if valid(mid):
                r = mid
            else:
                l = mid + 1
        return l