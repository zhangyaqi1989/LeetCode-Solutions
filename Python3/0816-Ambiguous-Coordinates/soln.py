class Solution:
    def ambiguousCoordinates(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        def valid(x):
            if '.' not in x:
                return str(int(x)) == x
            else:
                idx = x.find('.')
                int_part, frac_part = x[:idx], x[idx + 1:]
                if len(int_part) > 1 and int_part[0] == '0':
                    return False
                if len(frac_part) > 0 and frac_part[-1] == '0':
                    return False
                return True
        S = S[1:-1]
        n = len(S)
        ans = []
        for i in range(1, n):
            left, right = S[:i], S[i:]
            for x in [left] + ['{}.{}'.format(left[:k], left[k:]) for k in range(1, len(left))]:
                if not valid(x):
                    continue
                for y in [right] + ['{}.{}'.format(right[:j], right[j:]) for j in range(1, len(right))]:
                    if valid(y):
                        ans.append('({}, {})'.format(x, y))
        # print(valid("1.23"))
        return ans
