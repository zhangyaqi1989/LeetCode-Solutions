class Solution:
    def splitArraySameAverage(self, A: List[int]) -> bool:
        total = sum(A)
        n = len(A)
        m = n // 2
        if all(total * i % n != 0 for i in range(1, m + 1)):
            return False
        sums = [set() for i in range(m + 1)]
        sums[0].add(0)
        for num in A:
            for i in range(m, 0, -1):
                for item in sums[i - 1]:
                    sums[i].add(item + num)
        for i in range(1, m + 1):
            if total * i % n == 0 and total * i // n in sums[i]:
                return True
        return False
