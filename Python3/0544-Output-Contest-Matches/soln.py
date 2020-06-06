class Solution:
    def findContestMatch(self, n):
        """
        :type n: int
        :rtype: str
        """
        ans = list(range(1, n + 1))
        while len(ans) > 1:
            ans = ["({},{})".format(ans[i], ans[~i]) for i in range(len(ans) // 2)]
        return ans[0]