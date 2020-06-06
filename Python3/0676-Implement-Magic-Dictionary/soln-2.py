class MagicDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.m = collections.Counter()
        self.words = set()
        
    def _possibles(self, word : 'str') -> 'Generator':
        n = len(word)
        for i in range(n):
            yield word[:i] + '#' + word[i + 1:]
        
        

    def buildDict(self, word_dict: 'List[str]') -> 'None':
        """
        Build a dictionary through a list of words
        """
        for word in word_dict:
            self.words.add(word)
            for temp in self._possibles(word):
                self.m[temp] += 1
        

    def search(self, word: 'str') -> 'bool':
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        """
        val = 1 if word in self.words else 0
        return any(self.m[temp] > val for temp in self._possibles(word))
        


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)
