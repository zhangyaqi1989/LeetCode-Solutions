class ExamRoom(object):

    def __init__(self, N):
        """
        :type N: int
        """
        self.N, self.L = N, []
        

    def seat(self):
        """
        :rtype: int
        """
        if not self.L:
            idx = 0
        else:
            idx, dis = 0, self.L[0]
            for a, b in zip(self.L, self.L[1:]):
                temp = (b - a) // 2
                if temp > dis:
                    dis = temp
                    idx = a + temp
            if self.N - 1 - self.L[-1] > dis:
                idx = self.N - 1
        bisect.insort(self.L, idx)
        return idx
        

    def leave(self, p):
        """
        :type p: int
        :rtype: void
        """
        self.L.remove(p)
        


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(N)
# param_1 = obj.seat()
# obj.leave(p)