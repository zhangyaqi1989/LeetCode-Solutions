class Solution:
    def fixedPoint(self, A: List[int]) -> int:
        for i, num in enumerate(A):
            if num == i:
                return i
        return -1
