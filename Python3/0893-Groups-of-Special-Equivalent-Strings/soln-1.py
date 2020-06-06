class Solution:
    def numSpecialEquivGroups(self, A: List[str]) -> int:
        def encode(string):
            return tuple(sorted(string[::2]) + sorted(string[1::2]))
        return len(set(encode(a) for a in A))
