class Solution:
    def shortestWordDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        idxes1, idxes2 = [], []
        for i, word in enumerate(words):
            if word == word1:
                idxes1.append(i)
            # this is important
            if word == word2:
                idxes2.append(i)
        return min(abs(i - j) for i in idxes1 for j in idxes2 if i != j)