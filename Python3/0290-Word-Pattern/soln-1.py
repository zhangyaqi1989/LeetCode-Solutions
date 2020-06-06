class Solution:
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        words = str.split()
        lps = len(set(pattern))
        lss = len(set(words))
        return len(pattern) == len(words) and lps == lss and lps == len(set(zip(pattern, words)))