class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        def find(x, parents):
            if parents[x] == x:
                return x
            parents[x] = find(parents[x], parents)
            return parents[x]
        sorted_edges_idxes = sorted(range(len(edges)), key=lambda idx : edges[idx][-1])
        def MST(remove=None):
            parents = list(range(n))
            cost = 0
            ncoms = n
            for idx in sorted_edges_idxes:
                if remove is not None and remove == idx:
                    continue
                u, v, w = edges[idx]
                ru, rv = find(u, parents), find(v, parents)
                if ru == rv:
                    continue
                parents[ru] = rv
                ncoms -= 1
                cost += w
            return cost if ncoms == 1 else math.inf
        def helper():
            psudo = [False] * len(edges)
            groups = collections.defaultdict(list)
            for i, (u, v, w) in enumerate(edges):
                groups[w].append((u, v, i))
            parents = list(range(n))
            cost = 0
            for w in sorted(groups):
                uvis = groups[w]
                for u, v, idx in uvis:
                    ru, rv = find(u, parents), find(v, parents)
                    if ru != rv:
                        psudo[idx] = True
                for u, v, idx in uvis:
                    ru, rv = find(u, parents), find(v, parents)
                    if ru == rv:
                        continue
                    parents[ru] = rv
                    cost += w
            return psudo         
        # psudo ?
        # can be in one edges
        # which edge can not be in MST
        best = MST()
        critical_edges = []
        for i in range(len(edges)):
            cur = MST(remove = i)
            if cur > best:
                critical_edges.append(i)
        psudo = helper()
        cri_set = set(critical_edges)
        return [critical_edges, [i for i in range(len(edges)) if psudo[i] and i not in cri_set]]
