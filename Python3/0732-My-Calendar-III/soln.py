class MyCalendarThree:
    
    def __init__(self):
        self.times = collections.defaultdict(int)

    def book(self, start: int, end: int) -> int:
        self.times[start] += 1
        self.times[end] -= 1
        mx = cur = 0
        for t in sorted(self.times):
            cur += self.times[t]
            mx = max(mx, cur)
        return mx


# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(start,end)
