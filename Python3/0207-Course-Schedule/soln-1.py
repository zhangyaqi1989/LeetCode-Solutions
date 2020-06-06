class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        degrees = [0] * numCourses
        frees = []
        graph = collections.defaultdict(list)
        for a, b in prerequisites:
            degrees[a] += 1
            graph[b].append(a)
        for i in range(numCourses):
            if degrees[i] == 0:
                frees.append(i)
        cnt = 0
        while frees:
            node = frees.pop()
            cnt += 1
            for nei in graph[node]:
                degrees[nei] -= 1
                if degrees[nei] == 0:
                    frees.append(nei)
        return cnt == numCourses
