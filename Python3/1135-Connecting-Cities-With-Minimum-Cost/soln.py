class Solution:
    def minimumCost(self, N: int, connections: List[List[int]]) -> int:
        def find(x):
            if x == parents[x]:
                return x
            else:
                parents[x] = find(parents[x])
                return parents[x]
        parents = list(range(N))
        min_cost = cnt = 0
        connections.sort(key=operator.itemgetter(2))
        for u, v, w in connections:
            u -= 1
            v -= 1
            ru, rv = find(u), find(v)
            if ru != rv:
                parents[ru] = rv
                cnt += 1;
                min_cost += w
                if cnt == N - 1:
                    return min_cost
        return min_cost if cnt == N - 1 else -1
