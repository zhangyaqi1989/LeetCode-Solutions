class Vector2D:

    def __init__(self, v):
        """
        :type v: List[List[int]]
        """
        self.iter = itertools.chain.from_iterable(v)
        self.cnt = sum(len(lst) for lst in v)
        

    def next(self):
        """
        :rtype: int
        """
        self.cnt -= 1
        return next(self.iter)
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.cnt > 0
        


# Your Vector2D object will be instantiated and called as such:
# obj = Vector2D(v)
# param_1 = obj.next()
# param_2 = obj.hasNext()
