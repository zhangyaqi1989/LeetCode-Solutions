class Solution:
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 0:
            return 0
        unit, ans, num = 1, 0, n
        while num:
            digit = num % 10
            num //= 10
            ans += num * unit
            if digit == 1:
                ans += n % unit + 1
            elif digit > 1:
                ans += unit
            unit *= 10
        return ans
        
# xyzdabc
# (1) xyz * 1000                     if d == 0
# (2) xyz * 1000 + abc + 1           if d == 1
# (3) xyz * 1000 + 1000              if d > 1