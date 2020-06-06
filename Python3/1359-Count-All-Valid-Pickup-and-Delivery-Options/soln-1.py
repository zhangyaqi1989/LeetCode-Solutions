class Solution:
    def countOrders(self, n: int) -> int:
        mod = 1000000007
        f = 1
        for i in range(2, n + 1):
            new_f = i * (f * (2 * i - 1)) % mod
            f = new_f
        return f
