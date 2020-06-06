class Solution:
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        cs, cg = collections.Counter(secret), collections.Counter(guess)
        bulls = sum(s == g for s, g in zip(secret, guess))
        cows = sum(min(cs[key], cg[key]) for key in cs & cg) - bulls
        return '{:d}A{:d}B'.format(bulls, cows)