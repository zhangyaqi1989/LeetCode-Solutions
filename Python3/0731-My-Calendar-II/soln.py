class MyCalendarTwo(object):

    def __init__(self):
        self.singles = []
        self.doubles = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        if any(start < e and end > s for s, e in self.doubles):
            return False
        for s, e in self.singles:
            if start < e and end > s:
                self.doubles.append((max(start, s), min(end, e)))
        self.singles.append((start, end))
        return True
        


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)