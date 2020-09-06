class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        # minimum spanning tree
        parents_a = list(range(n))
        parents_b = list(range(n))
        cnt_a = n
        cnt_b = n
        def find(x, parents):
            if parents[x] == x:
                return x
            parents[x] = find(parents[x], parents)
            return parents[x]
        def unite(u, v, parents):
            ru, rv = find(u, parents), find(v, parents)
            if ru == rv:
                return 0
            else:
                parents[ru] = rv
                return 1
        nused = 0
        for t, u, v in sorted(edges, key=lambda x : -x[0]):
            u -= 1
            v -= 1
            use = False
            if t == 1:
                nremoved = unite(u, v, parents_a)
                if nremoved == 1:
                    use = True
                cnt_a -= nremoved
            elif t == 2:
                nremoved = unite(u, v, parents_b)
                if nremoved == 1:
                    use = True
                cnt_b -= nremoved
            else:
                nremoved = unite(u, v, parents_a)
                if nremoved == 1:
                    use = True
                cnt_a -= nremoved
                nremoved = unite(u, v, parents_b)
                if nremoved == 1:
                    use = True
                cnt_b -= nremoved
            if use:
                nused += 1
            if cnt_a == 1 and cnt_b == 1:
                return len(edges) - nused
        return -1
