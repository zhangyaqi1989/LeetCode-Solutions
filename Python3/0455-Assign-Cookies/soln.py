class Solution:
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        cnt = 0
        g.sort()
        s.sort()
        i = 0
        for item in g:
            while i < len(s) and s[i] < item:
                i += 1
            if i < len(s):
                cnt += 1
                i += 1
            else:
                break
        return cnt