class RangeModule:

    def __init__(self):
        self.intervals = []
        

    def addRange(self, left: int, right: int) -> None:
        intervals = self.intervals
        temp = []
        n = len(intervals)
        for i in range(n + 1):
            if i == n or intervals[i][0] > right:
                temp.append((left, right))
                for j in range(i, n):
                    temp.append(intervals[j])
                break
            elif intervals[i][1] < left:
                temp.append(intervals[i])
            else:
                left = min(left, intervals[i][0])
                right = max(right, intervals[i][1])
        self.intervals = temp;

    def queryRange(self, left: int, right: int) -> bool:
        intervals = self.intervals
        lo, hi = 0, len(intervals) - 1
        while lo <= hi:
            mid = (lo + hi) // 2
            if intervals[mid][1] < left:
                lo = mid + 1
            elif intervals[mid][0] > right:
                hi = mid - 1
            else:
                return intervals[mid][0] <= left and intervals[mid][1] >= right
        return False
        

    def removeRange(self, left: int, right: int) -> None:
        intervals = self.intervals
        n = len(intervals)
        temp = []
        for i in range(n):
            if intervals[i][1] < left:
                temp.append(intervals[i])
            elif intervals[i][0] > right:
                temp.append(intervals[i])
            else:
                if intervals[i][0] < left:
                    temp.append((intervals[i][0], left))
                if intervals[i][1] > right:
                    temp.append((right, intervals[i][1]))
        self.intervals = temp


# Your RangeModule object will be instantiated and called as such:
# obj = RangeModule()
# obj.addRange(left,right)
# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)
