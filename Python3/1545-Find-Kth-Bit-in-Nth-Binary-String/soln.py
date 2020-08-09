class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        # S1 = "0"
        lst = [0]
        for _ in range(n - 1):
            lst = lst + [1] + [1 - v for v in reversed(lst)]
        return "1" if lst[k - 1] == 1 else "0"
