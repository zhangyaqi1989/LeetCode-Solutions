# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
#class Master:
#    def guess(self, word):
#        """
#        :type word: str
#        :rtype int
#        """

class Solution:
    def findSecretWord(self, wordlist, master):
        """
        :type wordlist: List[Str]
        :type master: Master
        :rtype: None
        """
        def match(word1, word2):
            return sum(ch1 == ch2 for ch1, ch2 in zip(word1, word2))
        for i in range(10):
            count = collections.Counter()
            for w1, w2 in itertools.product(wordlist, wordlist):
                if match(w1, w2) == 0:
                    count[w1] += 1
            word = min(wordlist, key=lambda x: count[x])
            x = master.guess(word)
            if x == 6:
                break
            wordlist = [item for item in wordlist if match(word, item) == x]