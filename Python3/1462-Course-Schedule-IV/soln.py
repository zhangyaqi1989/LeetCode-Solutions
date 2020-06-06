class Solution:
    def checkIfPrerequisite(self, n: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        graph = collections.defaultdict(list)
        innodes = collections.defaultdict(list)
        indegrees = [0] * n
        for u, v in prerequisites:
            indegrees[v] += 1
            graph[u].append(v)
            innodes[v].append(u)
        frees = []
        levels = {}
        level = 0
        pres = [set() for _ in range(n)]
        for u in range(n):
            if not indegrees[u]:
                frees.append(u)
        while frees:
            next_level = []
            for u in frees:
                levels[u] = level
                pre = set()
                for parent in innodes[u]:
                    pre.add(parent)
                    pre |= pres[parent]
                pres[u] = pre
                for v in graph[u]:
                    indegrees[v] -= 1
                    if indegrees[v] == 0:
                        next_level.append(v)
            frees = next_level
            level += 1
        return [u in pres[v] for u, v in queries]
