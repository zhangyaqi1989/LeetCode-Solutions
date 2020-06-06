# The knows API is already defined for you.
# @param a, person a
# @param b, person b
# @return a boolean, whether a knows b
# def knows(a, b):

class Solution(object):
    def findCelebrity(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        for i in range(1, n):
            if knows(ans, i):
                ans = i
        return ans if all(knows(i, ans) and not knows(ans, i) for i in range(n) if i != ans) else -1