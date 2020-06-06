class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], num_wanted: int, use_limit: int) -> int:
        idxes = list(range(len(values)))
        ans = 0
        m = collections.Counter()
        for idx in sorted(idxes, key=lambda x : values[x], reverse=True):
            label = labels[idx]
            if m[label] < use_limit:
                m[label] += 1
                ans += values[idx]
                num_wanted -= 1
                if not num_wanted:
                    break
        return ans
