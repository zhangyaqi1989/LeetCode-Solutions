class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        arr2.sort()
        level = {-1 : 0}
        for num in arr1:
            nxt_level = {}
            for end, cnt in level.items():
                if num > end:
                    nxt_level[num] = min(nxt_level.get(num, math.inf), cnt)
                # find a possible number that > end
                idx = bisect.bisect_right(arr2, end)
                if idx < len(arr2):
                    nxt_level[arr2[idx]] = min(nxt_level.get(arr2[idx], math.inf), cnt + 1)
            level = nxt_level
            if not level:
                return -1
        return min(level.values())
