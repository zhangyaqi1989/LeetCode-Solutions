class Solution:
    def shortestDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        idxs1, idxs2 = [], []
        for i, word in enumerate(words):
            if word == word1:
                idxs1.append(i)
            elif word == word2:
                idxs2.append(i)
        return min(abs(a - b) for a, b in itertools.product(idxs1, idxs2))