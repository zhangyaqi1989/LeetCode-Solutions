class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        merged = []
        for s, e in sorted(intervals):
            if not merged or s > merged[-1][-1]:
                merged.append([s, e])
            else:
                merged[-1][-1] = max(merged[-1][-1], e)
        return merged
