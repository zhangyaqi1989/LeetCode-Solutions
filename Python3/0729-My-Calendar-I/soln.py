from bisect import bisect_left as bl, bisect_right as br
class MyCalendar:

    def __init__(self):
        self.cals = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        left, right = br(self.cals, start), bl(self.cals, end)
        if left == right and left % 2 == 0:
            left, right = bl(self.cals, start), br(self.cals, end)
            self.cals[left:right] = [start] * (left % 2 == 0) + [end] * (right % 2 == 0)
            return True
        return False
        
        


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)