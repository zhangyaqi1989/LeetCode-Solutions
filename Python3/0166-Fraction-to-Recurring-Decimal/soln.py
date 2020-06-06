class Solution:
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        sign = -1 if numerator * denominator < 0 else 1
        num, deno = abs(numerator), abs(denominator)
        q, r = divmod(num, deno)
        ans = str(q) + ('.' if r else '')
        d = {}
        while r:
            if r in d:
                ans = ans[:d[r]] + '(' + ans[d[r]:] + ')'
                break
            else:
                d[r] = len(ans)
                q, r = divmod(r * 10, deno)
                ans += str(q)
        return ans if sign == 1 else '-' + ans