class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        idx, n = -1, len(digits)
        for i, digit in enumerate(digits):
            if digit != 9:
                idx = i
        digits[idx + 1:] = [0] * (n - idx - 1)
        if idx == -1:
            return [1] + digits
        else:
            digits[idx] += 1
            return digits
