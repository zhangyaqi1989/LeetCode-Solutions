class Solution:
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        seats = ''.join(map(str, seats))
        l, r = seats.index('1'), seats.rindex('1')
        return max(max(l, len(seats) - 1 - r), max([(len(list(g)) + 1) // 2 for ch, g in itertools.groupby(seats[l:r]) if ch == '0'] or [0]))  