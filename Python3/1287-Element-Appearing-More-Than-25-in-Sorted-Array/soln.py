class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        m = len(arr) // 4
        for val, g in itertools.groupby(arr):
            n = len(list(g))
            if n > m:
                return val
