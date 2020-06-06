class Solution:
    def minAddToMakeValid(self, S):
        """
        :type S: str
        :rtype: int
        """
        # as soon as you find a negative cnt, res += 1
        res = 0
        cnt = 0
        for ch in S:
            if ch == '(':
                cnt += 1
            else:
                cnt -= 1
                if cnt < 0:
                    res += 1
                    cnt += 1
        return res + cnt