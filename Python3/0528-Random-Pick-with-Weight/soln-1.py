class Solution:

    def __init__(self, w: List[int]):
        self.ws = list(itertools.accumulate(w))
        self.end = self.ws[-1]

    def pickIndex(self) -> int:
        num = random.randint(1, self.end)
        return bisect.bisect_left(self.ws, num)
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
