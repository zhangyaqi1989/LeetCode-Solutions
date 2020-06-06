class Solution:
    def search(self, reader, target):
        """
        :type reader: ArrayReader
        :type target: int
        :rtype: int
        """
        r = 1
        while reader.get(r) != 2147483647:
            r *= 2
        if r == 1:
            return 0 if reader.get(0) == target else -1
        l = 0
        while l <= r:
            mid = (l + r) >> 1
            if reader.get(mid) == target:
                return mid
            elif reader.get(mid) < target:
                l = mid + 1
            else:
                r = mid - 1
        return -1