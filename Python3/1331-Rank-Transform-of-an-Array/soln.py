class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        ranks = {}
        for num in sorted(arr):
            if num not in ranks:
                ranks[num] = len(ranks) + 1
        return [ranks[num] for num in arr]
