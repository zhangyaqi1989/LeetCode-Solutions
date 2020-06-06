class Solution(object):
    def binaryGap(self, N):
        """
        :type N: int
        :rtype: int
        """
        pre, ans = None, 0
        for i, ch in enumerate(bin(N)[2:]):
            if ch == '1':
                if pre is None:
                    pre = i
                else:
                    ans = max(ans, i - pre)
                    pre = i
        return ans