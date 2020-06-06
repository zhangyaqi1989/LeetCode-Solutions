class Solution:

    def __init__(self, n_rows, n_cols):
        """
        :type n_rows: int
        :type n_cols: int
        """
        self.size = n_rows * n_cols
        self.seen = set()
        self.n_cols = n_cols
        

    def flip(self):
        """
        :rtype: List[int]
        """
        while True:
            n = random.randrange(self.size)
            if n not in self.seen:
                self.seen.add(n)
                return divmod(n, self.n_cols)

    def reset(self):
        """
        :rtype: void
        """
        self.seen = set()
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(n_rows, n_cols)
# param_1 = obj.flip()
# obj.reset()
