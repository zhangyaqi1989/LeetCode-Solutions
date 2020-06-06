class Solution:
    def addNegabinary(self, A: List[int], B: List[int]) -> List[int]:
        def toNum(lst):
            ans = 0
            for num in lst:
                ans = ans * (-2) + num
            return ans
        def toBase2(N):
            if N == 0:
                return [0]
            ans = collections.deque([])
            while N != 0:
                r = N % (-2)
                N //= (-2)
                if r < 0:
                    r += 2
                    N += 1
                ans.appendleft(r)
            return list(ans)
        return toBase2(toNum(A) + toNum(B))
