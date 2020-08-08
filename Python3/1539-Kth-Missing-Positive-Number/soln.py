class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        pool = set(arr)
        for i in range(1, 10000):
            if i not in pool:
                k -= 1
                if k == 0:
                    return i
        return -1
