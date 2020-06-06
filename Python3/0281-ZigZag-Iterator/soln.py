class ZigzagIterator(object):

    def __init__(self, v1, v2):
        """
        Initialize your data structure here.
        :type v1: List[int]
        :type v2: List[int]
        """
        n1, n2 = len(v1), len(v2)
        nmin = min(n1, n2)
        self.v = [0] * (n1 + n2)
        self.v[:2 * nmin:2] = v1[:nmin]
        self.v[1:2 * nmin:2] = v2[:nmin]
        self.v[2*nmin:] = (v1, v2)[n1 < n2][nmin:]
        self.i = 0
        

    def next(self):
        """
        :rtype: int
        """
        val = self.v[self.i]
        self.i += 1
        return val
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.i < len(self.v)

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())
