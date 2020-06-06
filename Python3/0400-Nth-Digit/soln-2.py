class Solution:
    def findNthDigit(self, n: int) -> int:
        # 1: 9
        # 2: 10 - 99, 90
        width, cnt = 1, 9
        while n:
            if n > width * cnt:
                n -= width * cnt
                width += 1
                cnt *= 10
            else:
                n -= 1
                lo = 10 ** (width - 1)
                num = lo + (n // width)
                return str(num)[n % width]
