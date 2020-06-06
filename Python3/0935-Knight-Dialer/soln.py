class Solution:
    def knightDialer(self, N):
        """
        :type N: int
        :rtype: int
        """
        xs = [1] * 10
        m = [(4, 6), (6, 8), (7, 9), (4, 8), (3, 9, 0), (), (1, 7, 0), (2, 6), (1, 3), (4, 2)]
        for _ in range(N - 1):
            temp = [0] * 10
            for i in range(10):
                for j in m[i]:
                    temp[i] += xs[j]
            xs = temp
        return sum(xs) % 1000000007