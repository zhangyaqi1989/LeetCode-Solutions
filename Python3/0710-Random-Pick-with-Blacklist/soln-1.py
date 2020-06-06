ass Solution:

    def __init__(self, N, blacklist):
        """
        :type N: int
        :type blacklist: List[int]
        """
        blacklist = sorted(blacklist)
        b_set = set(blacklist)
        self.len = N - len(blacklist)
        self.m = {}
        j = 0
        for num in range(self.len, N):
            if num not in b_set:
                self.m[blacklist[j]] = num
                j += 1
        

    def pick(self):
        """
        :rtype: int
        """
        val = random.randrange(self.len)
        return val if val not in self.m else self.m[val]
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(N, blacklist)
# param_1 = obj.pick()
