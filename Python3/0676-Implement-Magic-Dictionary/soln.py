class MagicDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.words = None
        self.near = None
        
    def _neighbors(self, word):
        for i in range(len(word)):
            yield word[:i] + '*' + word[i + 1:]
        

    def buildDict(self, words):
        """
        Build a dictionary through a list of words
        :type words: List[str]
        :rtype: void
        """
        self.words = set(words)
        self.near = collections.Counter([nei for word in words for nei in self._neighbors(word)])
        

    def search(self, word):
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        :type word: str
        :rtype: bool
        """
        # modify word and it is in words
        return any(self.near[nei] > 1 or self.near[nei] == 1 and word not in self.words for nei in self._neighbors(word))
        


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)