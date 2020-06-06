class Solution:
    def maxVacationDays(self, flights: List[List[int]], days: List[List[int]]) -> int:
        cities, weeks = len(days), len(days[0])
        memo = [[-math.inf] * cities for _ in range(weeks)]
        graph = collections.defaultdict(list)
        for city in range(cities):
            graph[city].append(city)
            for nei, adj in enumerate(flights[city]):
                if adj:
                    graph[city].append(nei)
        return self.dfs(memo, 0, 0, weeks, cities, graph, days)
        
    def dfs(self, memo, cur_week, cur_city, weeks, cities, graph, days):
        if cur_week == weeks:
            return 0
        if memo[cur_week][cur_city] != -math.inf:
            return memo[cur_week][cur_city]
        res = 0
        for nei in graph[cur_city]:
            res = max(res, days[nei][cur_week] + self.dfs(memo, cur_week + 1, nei, weeks, cities, graph, days))
        
        memo[cur_week][cur_city] = res
        return res
