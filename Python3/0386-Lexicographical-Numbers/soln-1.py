class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ans = [1]
        while len(ans) < n:
            nxt = ans[-1] * 10
            while nxt > n:
                nxt //= 10
                nxt += 1
                while nxt % 10 == 0:
                    nxt //= 10
            ans.append(nxt)
        return ans
