class WordDistance(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.idxes = collections.defaultdict(list)
        for idx, word in enumerate(words):
            self.idxes[word].append(idx)
        

    def shortest(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        return min(abs(i - j) for i in self.idxes[word1] for j in self.idxes[word2])
        


# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(words)
# param_1 = obj.shortest(word1,word2)