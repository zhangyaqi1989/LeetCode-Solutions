class Solution:
    def encode(self, s, memo={}):
        """
        :type s: str
        :rtype: str
        """
        if s not in memo:
            n = len(s)
            i = (s + s).find(s, 1)
            one = "{:d}[{:s}]".format(n//i, self.encode(s[:i])) if i < n else s
            multi = [self.encode(s[:i]) + self.encode(s[i:]) for i in range(1, n)]
            memo[s] = min([s, one] + multi, key=len)
        return memo[s]