class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        median = arr[(len(arr) - 1) // 2]
        return heapq.nlargest(k, arr, key=lambda x : (abs(x - median), x))
