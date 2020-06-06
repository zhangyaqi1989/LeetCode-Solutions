class Solution:
    def isRationalEqual(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        def parse(s):
            if '.' not in s:
                return s, '', ''
            else:
                idx = s.find('.')
                int_part = s[:idx]
                right = s[idx + 1:]
                if '(' in right:
                    idx = right.find('(')
                    return int_part, right[:idx], right[idx + 1:-1]
                else:
                    return int_part, right, ''
        def ndigits(no_repeat, repeat, n=350):
            left = n - len(no_repeat)
            # print(left)
            if len(repeat) == 0:
                return no_repeat
            return no_repeat + repeat * (left // len(repeat)) + repeat[:left % len(repeat) + 1]
        int_s, nrepeat_s, repeat_s = parse(S)
        int_t, nrepeat_t, repeat_t = parse(T)
        # print(ndigits(nrepeat_s, repeat_s, 10))
        # print(ndigits(nrepeat_t, repeat_t, 10))
        # return int_s == int_t and ndigits(nrepeat_s, repeat_s) == ndigits(nrepeat_t, repeat_t)
        return float(int_s + '.' + ndigits(nrepeat_s, repeat_s)) == float(int_t + '.' + ndigits(nrepeat_t, repeat_t))
