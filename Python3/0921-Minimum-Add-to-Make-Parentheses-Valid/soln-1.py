class Solution:
    def minAddToMakeValid(self, S):
        """
        :type S: str
        :rtype: int
        """
        cnt, ans = 0, 0
        for ch in S:
            if ch == '(':
                cnt += 1
            else:
                cnt -= 1
                if cnt < 0:
                    ans += -cnt
                    cnt = 0
        return ans + cnt