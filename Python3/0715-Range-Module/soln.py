from bisect import bisect_left as bl, bisect_right as br
class RangeModule:

    def __init__(self):
        self._X = []
        

    def addRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: void
        """
        # [1, 4, 2, 5]
        l, r = bl(self._X, left), br(self._X, right)
        self._X[l:r] = [left] * (l % 2 == 0) + [right] * (r % 2 == 0)
        
        

    def queryRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: bool
        """
        l, r = br(self._X, left), bl(self._X, right)
        return l == r and l % 2 == 1
        

    def removeRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: void
        """
        l, r = bl(self._X, left), br(self._X, right)
        self._X[l:r] = [left] * (l % 2 == 1) + [right] * (r % 2 == 1)
        


# Your RangeModule object will be instantiated and called as such:
# obj = RangeModule()
# obj.addRange(left,right)
# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)