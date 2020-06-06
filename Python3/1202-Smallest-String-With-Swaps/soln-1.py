class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        n = len(s)
        parents = list(range(n))
        def find(x):
            if parents[x] == x:
                return x
            parents[x] = find(parents[x])
            return parents[x]
        def unite(x, y):
            rx, ry = find(x), find(y)
            if rx != ry:
                parents[rx] = ry
        for x, y in pairs:
            unite(x, y)
        groups = collections.defaultdict(list)
        for i, ch in enumerate(s):
            groups[find(i)].append((i, ch))
        ans = [None] * n
        for ps in groups.values():
            idxes, chars = list(zip(*ps))
            for ch, idx in zip(sorted(chars), sorted(idxes)):
                ans[idx] = ch
        return ''.join(ans)
