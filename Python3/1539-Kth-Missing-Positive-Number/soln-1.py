class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        idx = 0
        for nxt in itertools.count(1):
            if idx < len(arr) and arr[idx] == nxt:
                idx += 1
            else:
                k -= 1
                if k == 0:
                    return nxt
