class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        # upper lower
        # always put in upper
        self.lower = []
        self.upper = []

    def addNum(self, num: int) -> None:
        small = heapq.heappushpop(self.upper, -heapq.heappushpop(self.lower, -num))
        if len(self.upper) > len(self.lower):
            heapq.heappush(self.lower, -small)
        else:
            heapq.heappush(self.upper, small);

    def findMedian(self) -> float:
        if len(self.upper) == len(self.lower):
            return 0.5 * (self.upper[0] - self.lower[0])
        else:
            return self.upper[0]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
