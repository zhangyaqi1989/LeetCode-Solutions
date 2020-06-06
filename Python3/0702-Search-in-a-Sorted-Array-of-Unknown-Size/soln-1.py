class Solution:
    def search(self, reader, target):
        """
        :type reader: ArrayReader
        :type target: int
        :rtype: int
        """
        hi = 1
        while reader.get(hi) < target:
            hi <<= 1
        lo = hi >> 1
        while lo <= hi:
            mid = (lo + hi) >> 1
            r = reader.get(mid)
            if r == target:
                return mid
            elif r < target:
                lo = mid + 1
            else:
                hi = mid - 1
        return -1
