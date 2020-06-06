class Solution:
    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        cnt = 0
        groups = collections.defaultdict(list)
        for i, g in enumerate(group):
            if g == -1:
                group[i] = cnt + m
                cnt += 1
            groups[group[i]].append(i)
        degrees = [0] * (m + cnt)
        graphs = collections.defaultdict(set)
        follows = collections.defaultdict(list)
        for v, befores in enumerate(beforeItems):
            for u in befores:
                if group[u] != group[v]:
                    degrees[group[v]] += 1
                    follows[group[u]].append(group[v])
                else:
                    graphs[group[u]].add((u, v))
        frees = []
        for i in range(cnt + m):
            if degrees[i] == 0:
                frees.append(i)
        group_seq = []
        while frees:
            node = frees.pop()
            group_seq.append(node)
            for nei in follows[node]:
                degrees[nei] -= 1
                if degrees[nei] == 0:
                    frees.append(nei)
        if len(group_seq) != m + cnt:
            return []
        ans = []
        for gidx in group_seq:
            if len(groups[gidx]) == 1:
                ans.append(groups[gidx].pop())
            else:
                eles = groups[gidx]
                edges = graphs[gidx]
                degrees = {e : 0 for e in eles}
                follows = collections.defaultdict(set)
                for u, v in edges:
                    degrees[v] += 1
                    follows[u].add(v)
                frees = []
                for e in eles:
                    if degrees[e] == 0:
                        frees.append(e)
                seq = []
                while frees:
                    node = frees.pop()
                    seq.append(node)
                    for nei in follows[node]:
                        degrees[nei] -= 1
                        if degrees[nei] == 0:
                            frees.append(nei)
                if len(seq) == len(eles):
                    ans.extend(seq)
                else:
                    return []
        return ans
