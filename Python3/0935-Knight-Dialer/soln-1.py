class Solution:
    def knightDialer(self, N: int) -> int:
        moves = ((4, 6), (6, 8), (7, 9), (4, 8), (0, 3, 9), (), (1, 7, 0), (2, 6), (1, 3), (2, 4))
        mod = 10 ** 9 + 7
        ans = [1] * 10
        for i in range(N - 1):
            lst = [0] * 10
            for i, move in enumerate(moves):
                lst[i] = (lst[i] + sum(ans[j] for j in move)) % mod
            ans = lst
        return sum(ans) % mod
                
