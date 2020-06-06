class Solution:
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        np, ns = len(p), len(s)
        cp = collections.Counter(p)
        cs = collections.Counter(s[:np])
        ans = []
        for i in range(ns - np + 1):
            if cs == cp:
                ans.append(i)
            if i + np < ns:
                cs[s[i + np]] += 1
                cs[s[i]] -= 1
                if cs[s[i]] == 0:
                    cs.pop(s[i])
        return ans