class Solution(object):
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        def isSub(s, word):
            if not word: return True
            i, n = 0, len(word)
            for ch in s:
                if ch == word[i]:
                    i += 1
                    if i == n:
                        return True
            return False
        d.append("")
        return next((word for word in sorted(d, key=lambda x : (-len(x), x)) if isSub(s, word)))