class Solution:
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        def match(word1, word2):
            if len(word1) != len(word2): return False
            m1, m2 = {}, {}
            for a, b in zip(word1, word2):
                if a in m1 and m1[a] != b:
                    return False
                else:
                    m1[a] = b
                if b in m2 and m2[b] != a:
                    return False
                else:
                    m2[b] = a
            return True
        return [word for word in words if match(word, pattern)]