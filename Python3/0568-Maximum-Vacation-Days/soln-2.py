class Solution:
    def maxVacationDays(self, flights: List[List[int]], days: List[List[int]]) -> int:
        graph = collections.defaultdict(set)
        N = len(flights)
        for i in range(N):
            for j in range(N):
                if flights[i][j]:
                    graph[j].add(i)
        for i in range(N):
            graph[i].add(i)
        K = len(days[0])
        dp = [[-1] * N for _ in range(K)]
        for j in range(N):
            if j == 0 or flights[0][j]:
                dp[0][j] = days[j][0]
        for i in range(1, K):
            for j in range(N):
                for nei in graph[j]:
                    if dp[i - 1][nei] != -1:
                        dp[i][j] = max(dp[i][j], dp[i - 1][nei] + days[j][i])
        return max(dp[-1])
