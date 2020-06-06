class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        def say(string):
            return "".join(["{}{}".format(len(list(group)), ch) for ch, group in itertools.groupby(string)])
        x = '1'
        for _ in range(n - 1):
            x = say(x)
        return x