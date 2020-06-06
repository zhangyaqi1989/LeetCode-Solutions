class Solution:
    def isRectangleOverlap(self, rec1, rec2):
        """
        :type rec1: List[int]
        :type rec2: List[int]
        :rtype: bool
        """
        x11, y11, x12, y12 = rec1
        x21, y21, x22, y22 = rec2
        return not (x11 >= x22 or x21 >= x12 or y11 >= y22 or y21 >= y12)