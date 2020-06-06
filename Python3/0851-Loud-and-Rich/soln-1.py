class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        n = len(quiet)
        graph = collections.defaultdict(list)
        degrees = [0] * n
        for a, b in richer:
            graph[a].append(b)
            degrees[b] += 1
        frees = [i for i, degree in enumerate(degrees) if degree == 0]
        ans = list(range(n))
        while frees:
            node = frees.pop()
            for nei in graph[node]:
                degrees[nei] -= 1
                if quiet[ans[node]] < quiet[ans[nei]]:
                    ans[nei] = ans[node]
                if degrees[nei] == 0:
                    frees.append(nei)
        return ans
