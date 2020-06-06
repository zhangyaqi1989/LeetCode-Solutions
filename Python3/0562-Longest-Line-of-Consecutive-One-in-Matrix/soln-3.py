class Solution:
    def longestLine(self, M: List[List[int]]) -> int:
        if not any(M):
            return 0
        m, n = len(M), len(M[0])
        counter = collections.Counter()
        ans = 0
        for i, row in enumerate(M):
            for j, val in enumerate(row):
                for item in (1, i), (2, j), (3, i + j), (4, i - j):
                    if val == 1:
                        counter[item] += 1
                        ans = max(ans, counter[item])
                    else:
                        counter[item] = 0
        return ans
