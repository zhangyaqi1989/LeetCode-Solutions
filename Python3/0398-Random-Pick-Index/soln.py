class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.indexes = collections.defaultdict(list)
        for idx, num in enumerate(nums):
            self.indexes[num].append(idx)
        

    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        return random.choice(self.indexes[target])
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)