class Solution:
    def longestWord(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        words = set(words)
        return next((word for word in sorted(words, key=lambda x : (-len(x), x)) if all(word[:i] in words for i in range(1, len(word)))), '')