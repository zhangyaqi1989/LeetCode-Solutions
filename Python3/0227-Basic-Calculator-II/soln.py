class Solution:
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        ops = {'*' : operator.mul, '/' : operator.floordiv}
        def helper(sub):
            i, ans, pre_op = 0, 1, '*'
            sub += '*'
            for match in re.finditer('[*/]', sub):
                l, r = match.start(), match.end()
                op = sub[l:r]
                if l > i:
                    ans = ops[pre_op](ans, int(sub[i:l]))
                i = r
                pre_op = op
            return ans
        ans = 0
        s.replace(' ', '')
        i = 0
        s += '+'
        pre_sign = 1
        for match in re.finditer('[+-]', s):
            l, r = match.start(), match.end()
            sign = 1 if s[l:r] == '+' else -1
            if l - i > 0:
                ans += pre_sign * (helper(s[i:l]))
            i = r
            pre_sign = sign
        return ans