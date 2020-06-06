class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        words = set(wordDict)
        dp = [True] + [False] * len(s)
        for i in range(1, len(s) + 1):
            for j in reversed(range(i)):
                if dp[j] and s[j:i] in words:
                    dp[i] = True
                    break
        return dp[-1]