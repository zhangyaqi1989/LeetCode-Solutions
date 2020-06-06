class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        indegrees = [0] * (N + 1)
        out_degrees = [0] * (N + 1)
        for a, b in trust:
            indegrees[b] += 1
            out_degrees[a] += 1
        for i in range(1, N + 1):
            if indegrees[i] == N - 1 and out_degrees[i] == 0:
                return i
        return -1
