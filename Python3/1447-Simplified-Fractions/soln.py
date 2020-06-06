class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        ans = set()
        for deno in range(2, n + 1):
            for nume in range(1, deno):
                gcd = math.gcd(deno, nume)
                ans.add('{}/{}'.format(nume//gcd, deno//gcd))
        return list(ans)
