class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> List[int]:
        def manhattan(worker, bike):
            return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1])
        nw, nb = len(workers), len(bikes)
        dists = [(manhattan(workers[i], bikes[j]), i, j) for i in range(nw) for j in range(nb)]
        ans = [-1] * nw
        bused = [False] * nb
        wused = [False] * nw
        cnt = 0
        for _, i, j in sorted(dists):
            if not wused[i] and not bused[j]:
                ans[i] = j
                wused[i] = True
                bused[j] = True
                cnt += 1
                if cnt == nw:
                    break
        return ans
