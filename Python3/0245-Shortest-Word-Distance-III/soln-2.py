class Solution:
    def shortestWordDistance(self, words: 'List[str]', word1: 'str', word2: 'str') -> 'int':
        i1 = i2 = -1
        ans = math.inf
        equal = word1 == word2
        for i, word in enumerate(words):
            if word == word1:
                i1 = i
            if word == word2:
                if equal:
                    i1 = i2
                i2 = i
            if i1 != -1 and i2 != -1:
                ans = min(ans, abs(i1 - i2))
        return ans
