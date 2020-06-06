class Solution:
    def maximumSwap(self, num: int) -> int:
        digits = [int(ch) for ch in str(num)]
        for i in range(len(digits)):
            if digits[i] != 9:
                mx, idx = digits[i], i
                for j in range(i, len(digits)):
                    if digits[j] >= mx:
                        mx = digits[j]
                        idx = j
                if digits[idx] != digits[i]:
                    digits[idx], digits[i] = digits[i], digits[idx]
                    break
        ans = 0
        for digit in digits:
            ans = ans * 10 + digit
        return ans
