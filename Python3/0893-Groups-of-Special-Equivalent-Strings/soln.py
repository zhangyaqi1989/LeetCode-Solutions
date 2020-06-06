class Solution:
    def numSpecialEquivGroups(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        def encode(s):
            return ''.join(sorted(s[::2]) + sorted(s[1::2]))
        d = set(encode(word) for word in A)
        return len(d)