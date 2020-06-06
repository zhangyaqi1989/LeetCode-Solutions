class Solution:
    def sumOfDigits(self, A: List[int]) -> int:
        return 0 if sum(map(int, str(min(A)))) & 1 else 1
