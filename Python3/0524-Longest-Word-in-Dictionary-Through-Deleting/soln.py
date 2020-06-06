class Solution:
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        def isSubsequence(sub, string):
            if not sub:
                return True
            i = 0
            for ch in string:
                if ch == sub[i]:
                    i += 1
                    if i == len(sub):
                        return True
            return False
        for word in sorted(d, key=lambda word : (-len(word), word)):
            if isSubsequence(word, s):
                return word
        return ''