class RLEIterator:

    def __init__(self, A: List[int]):
        self.i = 0
        self.A = A[:]
        
    def update(self, ):
        if self.i < len(self.A) and self.A[self.i] == 0:
            self.i += 2
        
        
    def next(self, n: int) -> int:
        while n:
            self.update()
            if self.i < len(self.A):
                val = self.A[self.i + 1]
                used = min(n, self.A[self.i])
                n -= used
                self.A[self.i] -= used
            else:
                val = -1
                break
        return val
                


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(A)
# param_1 = obj.next(n)
