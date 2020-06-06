class Solution:
    def numSpecialEquivGroups(self, A: List[str]) -> int:
        def encode(s):
            odds, evens = s[1::2], s[::2]
            return ''.join(sorted(evens) + sorted(odds))
        return len(set(encode(s) for s in A))
