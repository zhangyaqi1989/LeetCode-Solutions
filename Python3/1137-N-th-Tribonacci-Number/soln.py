class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        elif n <- 2:
            return 1
        lst = [0, 1, 1]
        while len(lst) <= n:
            lst.append(lst[-3] + lst[-2] + lst[-1])
        return lst[-1]
