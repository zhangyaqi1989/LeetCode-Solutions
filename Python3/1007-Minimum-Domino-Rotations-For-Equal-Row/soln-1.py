class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        n = len(A) + 1
        for val in range(1, 7):
            na = nb = 0
            for a, b in zip(A, B):
                if a != val and b != val:
                    break
                if a != val:
                    na += 1
                if b != val:
                    nb += 1
            else:
                n = min(n, na, nb)
        return -1 if n == len(A) + 1 else n
