class WordDistance:

    def __init__(self, words: 'List[str]'):
        self.idxes = collections.defaultdict(list)
        for i, word in enumerate(words):
            self.idxes[word].append(i)
        

    def shortest(self, word1: 'str', word2: 'str') -> 'int':
        idxes1, idxes2 = self.idxes[word1], self.idxes[word2]
        i1, i2 = 0, 0
        ans = math.inf
        while i1 < len(idxes1) and i2 < len(idxes2):
            ans = min(ans, abs(idxes1[i1] - idxes2[i2]))
            if idxes1[i1] < idxes2[i2]:
                i1 += 1
            else:
                i2 += 1
        return ans


# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(words)
# param_1 = obj.shortest(word1,word2)
