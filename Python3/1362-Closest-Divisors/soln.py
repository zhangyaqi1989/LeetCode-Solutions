class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        def helper(num):
            a, b = 1, num
            for f in range(2, int(math.sqrt(num)) + 1):
                if num % f == 0 and num // f - f < b - a:
                    a, b = f, num // f
            return a, b
        a1, b1 = helper(num + 1)
        a2, b2 = helper(num + 2)
        return (a1, b1) if b1 - a1 < b2 - a2 else (a2, b2)
