class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        n = len(arr)
        for i in range(1, n):
            arr[i] ^= arr[i - 1]
        return [(arr[hi] if lo == 0 else arr[hi] ^ arr[lo - 1]) for lo, hi in queries]
