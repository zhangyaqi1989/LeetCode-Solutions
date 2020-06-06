class Solution:

    def __init__(self, rects: List[List[int]]):
        self.rects = rects
        self.areas = [(x2 - x1 + 1) * (y2 - y1 + 1) for x1, y1, x2, y2 in rects]
        self.areas = list(itertools.accumulate(self.areas))
        self.end = self.areas[-1]
        

    def pick(self) -> List[int]:
        rand_num = random.randint(1, self.end)
        idx = bisect.bisect_left(self.areas, rand_num)
        x1, y1, x2, y2 = self.rects[idx]
        return random.randint(x1, x2), random.randint(y1, y2)
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()
