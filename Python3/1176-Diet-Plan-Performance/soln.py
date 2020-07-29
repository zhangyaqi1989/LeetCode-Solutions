class Solution:
    def dietPlanPerformance(self, calories: List[int], k: int, lower: int, upper: int) -> int:
        ncalories = 0
        npoints = 0
        for i, c in enumerate(calories):
            ncalories += c
            if i >= k:
                ncalories -= calories[i - k]
            if i >= k - 1:
                if ncalories < lower:
                    npoints -= 1
                elif ncalories > upper:
                    npoints += 1
        return npoints
