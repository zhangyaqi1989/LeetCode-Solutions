class Solution:

    def __init__(self, w):
        """
        :type w: List[int]
        """
        self.w = [0] + list(itertools.accumulate(w))
        self.max_num = self.w[-1]
        

    def pickIndex(self):
        """
        :rtype: int
        """
        rand = random.uniform(0, self.max_num)
        return bisect.bisect(self.w, rand) - 1
        
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()