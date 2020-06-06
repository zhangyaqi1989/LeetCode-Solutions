class Solution:
    def minAreaFreeRect(self, points: List[List[int]]) -> float:
        cpoints = [complex(x, y) for x, y in sorted(points)]
        lines = collections.defaultdict(list)
        for A, B in itertools.combinations(cpoints, 2):
            lines[B - A].append((B + A) / 2)
        ans = math.inf
        for A, mids in lines.items():
            for P, Q in itertools.combinations(mids, 2):
                B = Q - P
                if A.real * B.real + A.imag * B.imag == 0:
                    ans = min(ans, abs(A) * abs(B))
        return 0 if ans == math.inf else ans
