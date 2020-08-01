class Solution:
    def earliestAcq(self, logs: List[List[int]], N: int) -> int:
        parents = list(range(N))
        def find(x):
            if parents[x] == x:
                return x
            parents[x] = find(parents[x])
            return parents[x]
        cnt = N
        for time, x, y in sorted(logs):
            rx, ry = find(x), find(y)
            if rx != ry:
                parents[rx] = ry
                cnt -= 1
                if cnt == 1:
                    return time
        return -1
