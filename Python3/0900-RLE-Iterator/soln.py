class RLEIterator:

    def __init__(self, A):
        """
        :type A: List[int]
        """
        self.A = A
        self.i = 0
        

    def next(self, n):
        """
        :type n: int
        :rtype: int
        """
        while n > 0 and self.i < len(self.A):
            if n > self.A[self.i]:
                n -= self.A[self.i]
                self.i += 2
            else: # n <= self.A[self.i]
                self.A[self.i] -= n
                return self.A[self.i + 1]
        return -1
            
        


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(A)
# param_1 = obj.next(n)