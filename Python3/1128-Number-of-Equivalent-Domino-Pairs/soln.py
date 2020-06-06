class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        counter = collections.defaultdict(int)
        for lst in dominoes:
            counter[tuple(sorted(lst))] += 1
        ans = 0
        for v in counter.values():
            if v >= 2:
                ans += v * (v - 1)
        return ans // 2
