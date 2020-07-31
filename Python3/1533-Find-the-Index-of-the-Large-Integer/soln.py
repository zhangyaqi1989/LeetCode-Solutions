# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
#class ArrayReader(object):
#	 # Compares the sum of arr[l..r] with the sum of arr[x..y]
#	 # return 1 if sum(arr[l..r]) > sum(arr[x..y])
#	 # return 1 if sum(arr[l..r]) > sum(arr[x..y])
#	 # return 1 if sum(arr[l..r]) > sum(arr[x..y])
#    def compareSub(self, l: int, r: int, x: int, y: int) -> int:
#
#	 # Returns the length of the array
#    def length(self) -> int:
#


class Solution:
    def getIndex(self, reader: 'ArrayReader') -> int:
        n = reader.length()
        lo, hi = 0, n - 1
        while lo < hi:
            mid = (lo + hi) >> 1
            if (hi - lo + 1) % 2 == 1:
                l, r = lo, mid - 1
                x, y = mid + 1, hi
                com = reader.compareSub(l, r, x, y)
                if com == 1:
                    lo, hi = l, r
                elif com == 0:
                    return mid
                else:
                    lo, hi = x, y
            else:
                l, r = lo, mid
                x, y = mid + 1, hi
                com = reader.compareSub(l, r, x, y)
                if com == 1:
                    lo, hi = l, r
                else:
                    lo, hi = x, y
        return lo
