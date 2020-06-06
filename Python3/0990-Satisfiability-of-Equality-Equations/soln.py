class Solution:
    def equationsPossible(self, equations: 'List[str]') -> 'bool':
        parents = list(range(26))
        def find(x):
            if parents[x] != x:
                parents[x] = find(parents[x])
            return parents[x]
        def unite(x, y):
            px, py = find(x), find(y)
            if px != py:
                parents[px] = py
        noequs = []
        for eq in equations:
            a, b, op = eq[0], eq[-1], eq[1]
            a, b = ord(a) - 97, ord(b) - 97
            if op == '=':
                unite(a, b)
            else:
                noequs.append((a, b))
        for a, b in noequs:
            if find(a) == find(b):
                return False
        return True
