class Solution:
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 2, 3, 5
        i2 = i3 = i5 = 0
        ugly = [1]
        while n > 1:
            while ugly[i2] * 2 <= ugly[-1]: i2 += 1
            while ugly[i3] * 3 <= ugly[-1]: i3 += 1
            while ugly[i5] * 5 <= ugly[-1]: i5 += 1
            ugly.append(min(ugly[i2] * 2, ugly[i3] * 3, ugly[i5]*5))
            n -= 1
        return ugly[-1]