class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        words = set(wordDict)
        memo = {len(s) : ['']}
        def sentence(i):
            if i not in memo:
                memo[i] = [s[i : j] + (tail and ' ' + tail)
                          for j in range(i + 1, len(s) + 1)
                          if s[i:j] in words
                          for tail in sentence(j)]
            return memo[i]
        return sentence(0)