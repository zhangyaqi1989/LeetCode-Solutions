class Solution:
    def isAlienSorted(self, words, order):
        """
        :type words: List[str]
        :type order: str
        :rtype: bool
        """
        order = dict(zip(order, range(len(order))))
        def check(word1, word2):
            "Check if word1 is before word2."
            for c1, c2 in zip(word1, word2):
                if order[c1] < order[c2]:
                    break
                elif order[c1] > order[c2]:
                    return False
            else:
                return len(word1) <= len(word2)
            return True
        return all(check(words[i], words[i + 1]) for i in range(len(words) - 1))
