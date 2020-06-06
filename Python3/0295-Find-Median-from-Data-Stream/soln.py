class MedianFinder:
    # use two heaps

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.min_heap = [] # responsible for the upper half
        self.max_heap = [] # responsible for the lower half
        self.size = 0

    def addNum(self, num):
        """
        :type num: int
        :rtype: void
        """
        heapq.heappush(self.min_heap, num)
        if len(self.min_heap) - len(self.max_heap) > 1:
            ele = heapq.heappop(self.min_heap)
            heapq.heappush(self.max_heap, -ele)
        if self.min_heap and self.max_heap and self.min_heap[0] < -self.max_heap[0]:
            ele = heapq.heappop(self.min_heap)
            rep = heapq.heapreplace(self.max_heap, -ele)
            heapq.heappush(self.min_heap, -rep)
        self.size += 1
        

    def findMedian(self):
        """
        :rtype: float
        """
        if self.size & 1 == 1:
            return self.min_heap[0]
        else:
            return 0.5 * (self.min_heap[0] - self.max_heap[0])
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()