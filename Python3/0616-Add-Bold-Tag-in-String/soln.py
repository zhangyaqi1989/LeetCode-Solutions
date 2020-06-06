class Solution:
    def addBoldTag(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: str
        """
        tags = [False] * len(s)
        n = len(s)
        for word in words:
            nw = len(word)
            for i in range(n - nw + 1):
                if s[i:i+nw] == word:
                    tags[i:i+nw] = [True] * nw
        res = []
        for tag, (idx, ch) in zip(tags, enumerate(s)):
            if tag:
                if idx == 0 or not tags[idx - 1]:
                    res.append('<b>')
                res.append(ch)
                if idx == n - 1 or not tags[idx + 1]:
                    res.append('</b>')
            else:
                res.append(ch)
        return ''.join(res)