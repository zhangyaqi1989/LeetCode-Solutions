class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        x, y = None, None
        cx, cy = 0, 0
        for num in nums:
            if num == x:
                cx += 1
            elif num == y:
                cy += 1
            elif cx == 0:
                x = num
                cx = 1
            elif cy == 0:
                y = num
                cy = 1
            else:
                cx -= 1
                cy -= 1
        ans = []
        if nums.count(x) > len(nums) // 3:
            ans.append(x)
        if nums.count(y) > len(nums) // 3:
            ans.append(y)
        return ans