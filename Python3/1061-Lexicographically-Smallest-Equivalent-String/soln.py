class Solution:
    def smallestEquivalentString(self, A: str, B: str, S: str) -> str:
        parents = {ch : ch for ch in string.ascii_lowercase}
        def find(x):
            if x == parents[x]:
                return parents[x]
            parents[x] = find(parents[x])
            return parents[x]
        def unite(x, y):
            rx, ry = find(x), find(y)
            if rx > ry:
                rx, ry = ry, rx
            # rx < ry
            parents[ry] = parents[rx]
        for a, b in zip(A, B):
            unite(a, b)
        return ''.join(map(find, S))
