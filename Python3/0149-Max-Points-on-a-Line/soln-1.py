class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        mx = 0
        counter = collections.Counter(tuple(p) for p in points)
        for (x0, y0), c0 in counter.items():
            slopes = collections.Counter()
            for (x, y), c in counter.items():
                if x == x0 and y == y0:
                    continue
                dx, dy = x - x0, y - y0
                g = math.gcd(dx, dy)
                dx //= g
                dy //= g
                slopes[dx, dy] += c
            mx = max(mx , max(slopes.values() or [0]) + c0)
        return mx
