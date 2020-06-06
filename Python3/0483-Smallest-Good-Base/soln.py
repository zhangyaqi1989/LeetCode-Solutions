class Solution:
    def smallestGoodBase(self, n: str) -> str:
        n = int(n)
        max_m = int(math.log(n,2))
        for m in range(max_m, 1, -1):
            k = int(n**m**-1)
            if (k**(m+1)-1)//(k-1) == n:
                return str(k)
        return str(n-1)
