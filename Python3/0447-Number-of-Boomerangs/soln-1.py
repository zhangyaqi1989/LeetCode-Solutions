class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        def dis(p1, p2):
            return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2
        ans = 0
        for point in points:
            counter = collections.Counter()
            for other in points:
                counter[dis(point, other)] += 1
            ans += sum(cnt * (cnt - 1) for cnt in counter.values())
        return ans
