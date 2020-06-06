class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        while True:
            a = random.randint(1, n - 1)
            b = n - a
            if '0' not in str(a) and '0' not in str(b):
                return [a, b]
