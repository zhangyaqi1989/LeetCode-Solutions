class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        def say(s):
            res = ''
            for ch, group in itertools.groupby(s):
                res += '{}{}'.format(len(list(group)), ch)
            return res
        content = '1'
        for _ in range(n - 1):
            content = say(content)
        return content