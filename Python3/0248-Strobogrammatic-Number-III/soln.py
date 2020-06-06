class Solution(object):
    def strobogrammaticInRange(self, low, high):
        """
        :type low: str
        :type high: str
        :rtype: int
        """
        m, n = len(low), len(high)
        low, high = int(low), int(high)
        nums = []
        for i in range(m, n + 1):
            nums.extend(self.generateNum(i))
        return sum(low <= num <= high for num in nums)

    def generateNum(self, n):
        if n & 1:
            ans = ['0', '1', '8']
        else:
            ans = ['']
        pairs = ['00', '11', '88', '69', '96']
        while n > 1:
            n -= 2
            ans = [pair[0] + item + pair[1] for item in ans for pair in pairs[n<2:]]
        return map(int, ans)