class Solution:
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        dis = lambda x, y: (x[0] - y[0]) ** 2 + (x[1] - y[1]) ** 2
        cnt = 0
        for point in points:
            counter = collections.Counter()
            for other in points:
                counter[dis(point, other)] += 1
            cnt += sum(cnt * (cnt - 1) for cnt in counter.values() if cnt >= 2)
        return cnt