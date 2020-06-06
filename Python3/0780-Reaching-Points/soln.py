class Solution:
    def reachingPoints(self, sx, sy, tx, ty):
        """
        :type sx: int
        :type sy: int
        :type tx: int
        :type ty: int
        :rtype: bool
        """
        while tx >= sx and ty >= sy:
            tx, ty = tx % ty, ty % tx
        return sx == tx and (ty - sy) % sx == 0 or sy == ty and (tx - sx) % sy == 0
