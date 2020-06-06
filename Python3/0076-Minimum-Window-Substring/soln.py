class Solution:
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        # sliding window
        ans, length = "", float('inf')
        cs = collections.Counter()
        ct = collections.Counter(t)
        i = 0
        for j, ch in enumerate(s):
            cs[ch] += 1
            while i < j and cs[s[i]] > ct[s[i]]:
                cs[s[i]] -= 1
                i += 1
            if all(cs[ch] >= cnt for ch, cnt in ct.items()):
                if j - i + 1 < length:
                    length = j - i + 1
                    ans = s[i:j + 1]
        return ans if length != float('inf') else ''