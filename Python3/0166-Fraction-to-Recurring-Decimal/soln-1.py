class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        sign = -1 if numerator * denominator < 0 else 1
        numerator = abs(numerator)
        denominator = abs(denominator)
        q, r = divmod(numerator, denominator)
        if r == 0:
            return str(q) if sign == 1 else "-{}".format(q)
        else:
            lst = []
            memo = {}
            left = r
            while left not in memo:
                val, r = divmod(left * 10, denominator)
                memo[left] = len(lst)
                lst.append(str(val))
                left = r
                if left == 0:
                    break
            else:
                lst.insert(memo[left], '(')
                lst.append(')')
            ans = "{}.{}".format(q, ''.join(lst))
            return ans if sign == 1 else "-" + ans
