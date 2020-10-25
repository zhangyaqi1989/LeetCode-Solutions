class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr.sort()
        m = len(arr) // 20
        return sum(arr[m:-m]) / (len(arr) - 2 * m)
