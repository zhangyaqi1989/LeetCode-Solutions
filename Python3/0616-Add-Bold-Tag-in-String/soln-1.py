class Solution:
    def addBoldTag(self, s, dict):
        """
        :type s: str
        :type dict: List[str]
        :rtype: str
        """
        n = len(s)
        flags = [0] * n
        for word in dict:
            m = len(word)
            for i in range(n - m + 1):
                if s[i:i + m] == word:
                    flags[i:i + m] = [True] * m
        ans = []
        for i, ch in enumerate(s):
            if flags[i]:
                if i == 0 or not flags[i - 1]:
                    ans.append('<b>')
            ans.append(ch)
            if flags[i]:
                if i == len(s) - 1 or not flags[i + 1]:
                    ans.append('</b>')
        return ''.join(ans)