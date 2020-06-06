class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        pool = []
        def helper(cand):
            if len(cand) == n:
                pool.append(''.join(cand))
            else:
                for nxt in 'abc':
                    if cand and cand[-1] == nxt:
                        continue
                    cand.append(nxt)
                    helper(cand)
                    cand.pop()
        helper([])
        if k > len(pool):
            return ""
        return sorted(pool)[k - 1]
