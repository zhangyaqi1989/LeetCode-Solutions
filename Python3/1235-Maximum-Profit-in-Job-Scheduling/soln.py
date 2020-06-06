class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs = [(e, s, p) for s, e, p in zip(startTime, endTime, profit)]
        jobs.sort()
        ends = [jobs[0][0]]
        dp = [jobs[0][-1]]
        n = len(jobs)
        for i in range(1, n):
            e, s, p = jobs[i]
            idx = bisect.bisect_right(ends, s)
            pre = dp[idx - 1] if idx > 0 else 0
            best = max(dp[-1], pre + p)
            dp.append(best)
            ends.append(e)
        return dp[-1]
