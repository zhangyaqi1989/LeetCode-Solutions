class Solution:
    def shortestDistance(self, words: 'List[str]', word1: 'str', word2: 'str') -> 'int':
        i1 = i2 = -1
        ans = math.inf
        for i, word in enumerate(words):
            if word1 == word:
                i1 = i
            elif word2 == word:
                i2 = i
            if i1 != -1 and i2 != -1:
                ans = min(ans, abs(i1 - i2))
        return ans
