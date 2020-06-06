class Vector2D(object):

    def __init__(self, vec2d):
        """
        Initialize your data structure here.
        :type vec2d: List[List[int]]
        """
        self.lst = list(itertools.chain.from_iterable(vec2d))
        self.i = 0
        

    def next(self):
        """
        :rtype: int
        """
        val = self.lst[self.i]
        self.i += 1
        return val
        
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.i < len(self.lst)
        
        

# Your Vector2D object will be instantiated and called as such:
# i, v = Vector2D(vec2d), []
# while i.hasNext(): v.append(i.next())
