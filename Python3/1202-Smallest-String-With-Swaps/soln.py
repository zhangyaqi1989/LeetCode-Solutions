class Solution(object):
    def smallestStringWithSwaps(self, s, pairs):
        """
        :type str: str
        :type pairs: List[List[int]]
        :rtype: str
        """
        # union find
        n = len(s)
        parents = list(range(n))
        def find(x):
            if x == parents[x]:
                return x
            parents[x] = find(parents[x])
            return parents[x]
        def unite(x, y):
            rx, ry = find(x), find(y)
            if rx != ry:
                parents[rx] = parents[ry]
        ps = set()
        for x, y in pairs:
            ps.add(x)
            ps.add(y)
            unite(x, y)
        groups = collections.defaultdict(list)
        for x in ps:
            groups[find(x)].append(x)
        ans = list(s)
        for idxes in groups.values():
            chars = [s[idx] for idx in idxes]
            for ch, idx in zip(sorted(chars), sorted(idxes)):
                ans[idx] = ch
        return ''.join(ans)
