class Solution:
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        ans = []
        i = 0
        while i < len(s):
            di = min(len(s) - i, k)
            ans.append(s[i:i + di][::-1])
            i += di
            di = min(len(s) - i, k)
            ans.append(s[i:i + di])
            i += di
        return ''.join(ans)