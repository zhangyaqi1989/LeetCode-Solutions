class Solution:
    def wordPattern(self, pattern, string):
        """
        :type pattern: str
        :type string: str
        :rtype: bool
        """
        m1, m2 = {}, {}
        words = string.split(' ')
        if len(words) != len(pattern):
            return False
        for ch, word in zip(pattern, words):
            if ch in m1 and m1[ch] != word:
                return False
            else:
                m1[ch] = word
            if word in m2 and m2[word] != ch:
                return False
            else:
                m2[word] = ch
        return True