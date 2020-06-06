class Solution:
    def largestTimeFromDigits(self, A):
        """
        :type A: List[int]
        :rtype: str
        """
        ans = ""
        time = -1
        for a, b, c, d in itertools.permutations(A):
            h = a * 10 + b
            m = c * 10 + d
            if h < 24 and m < 60:
                if h * 24 + m > time:
                    time = h * 24 + m
                    ans = '{}{}:{}{}'.format(a, b, c, d)
        return ans