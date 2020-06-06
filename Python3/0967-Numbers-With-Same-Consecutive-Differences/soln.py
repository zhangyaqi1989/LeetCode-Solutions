class Solution:
    def numsSameConsecDiff(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: List[int]
        """
        def lst2num(lst):
            val = 0
            for num in lst:
                val = val * 10 + num
            return val
        def dfs(cand, ans):
            if len(cand) == N:
                ans.add(lst2num(cand))
                return
            else:
                if len(cand) == 0:
                    start = 0 if N == 1 else 1
                    for i in range(start, 10):
                        dfs(cand + [i], ans)
                else:
                    for i in (cand[-1] + K, cand[-1] - K):
                        if 0 <= i <= 9:
                            dfs(cand + [i], ans)
        ans = set()
        dfs([], ans)
        return list(ans)
