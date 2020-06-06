class Solution:
    def minimumSemesters(self, N: int, relations: List[List[int]]) -> int:
        # topological sort for DAG?
        outs = [[] for _ in range(N)]
        indegrees = [0] * N
        for u, v in relations:
            u -= 1
            v -= 1
            indegrees[v] += 1
            outs[u].append(v)
        frontier = [i for i in range(N) if indegrees[i] == 0]
        step = 0
        taken = 0
        while frontier:
            nxt_level = []
            step += 1
            for u in frontier:
                taken += 1
                for v in outs[u]:
                    indegrees[v] -= 1
                    if not indegrees[v]:
                        nxt_level.append(v)
            frontier = nxt_level
        return step if taken == N else -1
