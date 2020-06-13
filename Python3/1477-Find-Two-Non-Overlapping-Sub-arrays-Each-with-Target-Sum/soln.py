class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        # need to know all subs
        n = len(arr)
        left = [math.inf] * n
        seen = {0 : -1}
        cur = 0
        for i, val in enumerate(arr):
            cur += val
            if i > 0:
                left[i] = left[i - 1]
            if cur - target in seen:
                left[i] = min(left[i], i - seen[cur - target])
            seen[cur] = i
        ans = math.inf
        cur = 0
        seen = {0 : n}
        old = math.inf
        for i in reversed(range(n)):
            cur += arr[i]
            best = old
            if cur - target in seen:
                best = min(best, seen[cur - target] - i)
                if i > 0 and left[i - 1] != -1:
                    ans = min(ans, left[i - 1] + best)
            seen[cur] = i
            old = best
        return ans if ans != math.inf else -1
