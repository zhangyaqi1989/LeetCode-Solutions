class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], num_wanted: int, use_limit: int) -> int:
        label_used = collections.Counter()
        pairs = [(v, l) for v, l in zip(values, labels)]
        ans = 0
        for v, l in sorted(pairs, reverse=True):
            if label_used[l] < use_limit:
                label_used[l] += 1
                ans += v
                num_wanted -= 1
                if num_wanted == 0:
                    break
        return ans
