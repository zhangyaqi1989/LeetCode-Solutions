class ValidWordAbbr:

    def __init__(self, dictionary):
        """
        :type dictionary: List[str]
        """
        self.abbs = collections.defaultdict(set)
        for word in dictionary:
            self.abbs[self._abbreviation(word)].add(word)
        
    def _abbreviation(self, word):
        if len(word) <= 2:
            return word
        return '{}{}{}'.format(word[0], len(word) - 2, word[-1])
        

    def isUnique(self, word):
        """
        :type word: str
        :rtype: bool
        """
        # no other word has the same abb
        abb = self._abbreviation(word)
        return (not abb in self.abbs) or (len(self.abbs[abb]) == 1 and word in self.abbs[abb])
        


# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param_1 = obj.isUnique(word)