import functools
class Solution(object):
    def strobogrammaticInRange(self, low, high):
        """
        :type low: str
        :type high: str
        :rtype: int
        """
        m, n = len(low), len(high)
        low, high = int(low), int(high)
        def generate(n):
            ans = ['1', '0', '8'] if n % 2 else ['']
            pairs = ['00', '11', '88', '69', '96']
            while n > 1:
                n -= 2
                ans = [pair[0] + item + pair[1] for item in ans for pair in pairs[n<2:]]
            return ans
        ans = functools.reduce(operator.add, [generate(i) for i in range(m, n + 1)], [])
        return sum(low <= int(num) <= high for num in ans)