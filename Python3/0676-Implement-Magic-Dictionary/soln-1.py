class MagicDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.poss = collections.defaultdict(int)
        self.words = set()
        
        
    def possibles(self, word):
        return {word[:i] + '#' + word[i + 1:] for i in range(len(word))}
        

    def buildDict(self, words):
        """
        Build a dictionary through a list of words
        :type words: List[str]
        :rtype: void
        """
        for word in words:
            self.words.add(word)
            for w in self.possibles(word):
                self.poss[w] += 1
        
        

    def search(self, word):
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        :type word: str
        :rtype: bool
        """
        words = self.possibles(word)
        return (word not in self.words and any(w in self.poss for w in words)) or (word in self.words and any(self.poss[w] > 1 for w in words))
        


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)