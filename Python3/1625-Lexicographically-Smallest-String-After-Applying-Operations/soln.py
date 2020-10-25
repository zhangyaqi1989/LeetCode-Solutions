class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        def add_op(t):
            return tuple((d if i % 2 == 0 else (d + a) % 10) for i, d in enumerate(t))
        def rotate_op(t):
            return t[-b:] + t[:-b]
        lst = tuple(int(ch) for ch in s)
        frontier = [lst]
        seen = set()
        while frontier:
            next_level = []
            for node in frontier:
                if node not in seen:
                    seen.add(node)
                    next_level.extend([add_op(node), rotate_op(node)])
            frontier = next_level
        return ''.join(map(str, min(seen)))
