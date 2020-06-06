class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        # [2, 4, 6, 8, 10], [10, 20, 30, 40, 50], [4,5,6,7]
        # for each work, find the most profit job that under his ability
        # profit / difficulty [5, 5, 5, 5, 5]
        cur = -1
        temp = [(d, p) for d, p in zip(difficulty, profit)]
        temp.sort()
        ds, ps = [], []
        for d, p in temp:
            if p <= cur:
                continue
            else:
                ds.append(d)
                ps.append(p)
                cur = p
        ans = 0
        for w in worker:
            idx = bisect.bisect_right(ds, w)
            if idx > 0:
                ans += ps[idx - 1]
        return ans
