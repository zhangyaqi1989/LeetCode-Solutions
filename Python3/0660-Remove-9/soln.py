class Solution:
    def newInteger(self, n):
        """
        :type n: int
        :rtype: int
        """
        lst = []
        while n:
            n, r = divmod(n, 9)
            lst.append(r)
        return int(''.join(map(str, lst[::-1])))
