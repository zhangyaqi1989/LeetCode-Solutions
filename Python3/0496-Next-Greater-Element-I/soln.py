class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        nexts = [-1] * len(nums)
        stack = []
        d = dict(zip(findNums, range(len(findNums))))
        for idx, num in enumerate(nums):
            if num in d:
                d[num] = idx
            while stack and num > nums[stack[-1]]:
                nexts[stack.pop()] = num
            stack.append(idx)
        res = []
        for num in findNums:
            res.append(nexts[d[num]])
        return res