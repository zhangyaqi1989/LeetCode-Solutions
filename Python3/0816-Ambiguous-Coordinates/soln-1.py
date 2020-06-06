class Solution:
    def ambiguousCoordinates(self, S: str) -> List[str]:
        def to_nums(s):
            n = len(s)
            cands = []
            for i in range(1, n):
                if s[0] == '0' and i > 1:
                    continue
                if s[-1] != '0' and any(ch != '0' for ch in s[i:]):
                    cands.append(s[:i] + '.' + s[i:])
            if s[0] != '0' or n == 1:
                cands.append(s)
            return cands
        S = S[1:-1]
        n = len(S)
        ans = []
        for i in range(1, n):
            left, right = S[:i], S[i:]
            for l, r in itertools.product(to_nums(left), to_nums(right)):
                ans.append('({}, {})'.format(l, r))
        return ans
