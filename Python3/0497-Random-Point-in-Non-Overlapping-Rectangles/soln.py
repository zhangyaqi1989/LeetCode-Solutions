class Solution:

    def __init__(self, rects):
        """
        :type rects: List[List[int]]
        """
        self.rects = rects
        acc = 0
        self.ranges = []
        for x1, y1, x2, y2 in rects:
            area = (x2 - x1 + 1) * (y2 - y1 + 1)
            acc += area
            self.ranges.append(acc)

    def pick(self):
        """
        :rtype: List[int]
        """
        idx = bisect.bisect_left(self.ranges, random.randint(1, self.ranges[-1]))
        x1, y1, x2, y2 = self.rects[idx]
        return [random.randint(x1, x2), random.randint(y1, y2)]
        
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()