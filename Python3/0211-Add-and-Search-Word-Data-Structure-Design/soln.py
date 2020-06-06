class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.words = collections.defaultdict(set)
        

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        self.words[len(word)].add(word)
        

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        if '.' not in word:
            return word in self.words[len(word)]
        for item in self.words[len(word)]:
            for a, b in zip(word, item):
                if a != '.' and a != b:
                    break
            else:
                return True
        return False
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)