class Solution:
    def shortestDistanceColor(self, colors: List[int], queries: List[List[int]]) -> List[int]:
        idxes = [[] for _ in range(4)]
        for i, c in enumerate(colors):
            idxes[c].append(i)
        ans = []
        for i, c in queries:
            lst = idxes[c]
            if not lst:
                ans.append(-1)
            else:
                idx = bisect.bisect_left(lst, i)
                if idx < len(lst):
                    best = lst[idx] - i
                    if idx - 1 >= 0:
                        best = min(best, i - lst[idx - 1])
                else:
                    best = i - lst[-1]
                ans.append(best)
        return ans
