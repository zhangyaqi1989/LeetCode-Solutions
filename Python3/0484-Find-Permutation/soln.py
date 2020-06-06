class Solution:
    def findPermutation(self, s):
        """
        :type s: str
        :rtype: List[int]
        """
        n = len(s)
        lst = list(range(1, n + 2))
        i = 0
        for ch, group in itertools.groupby(s):
            if ch == 'D':
                length = len(list(group))
                lst[i:i + length + 1] = lst[i:i + length + 1][::-1]
                i += length
            else:
                i += len(list(group))
        return lst