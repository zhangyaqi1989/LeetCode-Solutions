import functools
class Solution:
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        # this is a usage of gcd
        counter = collections.Counter(deck)
        return functools.reduce(math.gcd, counter.values()) >= 2