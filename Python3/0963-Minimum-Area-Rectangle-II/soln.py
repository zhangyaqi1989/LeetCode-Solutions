class Solution:
    def minAreaFreeRect(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """
        points = [complex(x, y) for x, y in sorted(points)]
        segs = collections.defaultdict(list)
        for P, Q in itertools.combinations(points, 2):
            segs[P - Q].append((P + Q) / 2)
        ans = math.inf
        for A, lst in segs.items():
            for P, Q in itertools.combinations(lst, 2):
                B = P - Q
                if A.real * B.real + A.imag * B.imag == 0:
                    ans = min(ans, abs(A) * abs(B))
        return 0 if ans == math.inf else ans
