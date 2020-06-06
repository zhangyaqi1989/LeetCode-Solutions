class Solution:
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        def encode(word):
            m = {}
            return [m.setdefault(c, len(m)) for c in word]
        return [word for word in words if encode(word) == encode(pattern)]