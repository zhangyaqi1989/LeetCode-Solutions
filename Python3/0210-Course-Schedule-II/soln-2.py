class Solution:
    def findOrder(self, n: int, edges: List[List[int]]) -> List[int]:
        follows = collections.defaultdict(list)
        degrees = [0] * n
        for v, u in edges:
            follows[u].append(v)
            degrees[v] += 1
        frees = []
        for i, d in enumerate(degrees):
            if not d:
                frees.append(i)
        ans = []
        while frees:
            course = frees.pop()
            ans.append(course)
            for nxt in follows[course]:
                degrees[nxt] -= 1
                if not degrees[nxt]:
                    frees.append(nxt)
        return ans if len(ans) == n else []
