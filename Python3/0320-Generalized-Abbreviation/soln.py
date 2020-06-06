class Solution:
    def generateAbbreviations(self, word):
        """
        :type word: str
        :rtype: List[str]
        """
        
        return [re.sub('#+', lambda m : str(len(m.group())), ''.join(t)) for t in itertools.product(* zip('#' * len(word), word))]